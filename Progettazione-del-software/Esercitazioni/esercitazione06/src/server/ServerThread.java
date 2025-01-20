package server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.Observable;
import java.util.Observer;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Implementation of {@code Runnable} that listens for client connections
 * and dispatches them to separate threads in a thread pool.
 */
public class ServerThread extends Observable implements Observer, Runnable {
    private static final Logger logger = Logger.getLogger(ServerThread.class.getName());
    private ThreadPoolExecutor pool;
    private ServerSocket serverSocket;
    private int port;
    private boolean running;

    public ServerThread(int port) {
        this.port = port;
        this.pool = (ThreadPoolExecutor) Executors.newCachedThreadPool();
    }

    /**
     * Returns the number of currently running client threads.
     *
     * @return the number of currently running client threads
     */
    public int getClientCount() {
        return pool.getActiveCount();
    }

    @Override
    public void run() {
        running = true;
        try {
            serverSocket = new ServerSocket(port);
            serverSocket.setSoTimeout(1000);
        } catch (IOException e) {
            logger.log(Level.SEVERE, "I/O error opening server socket, exiting...", e);
            running = false;
            return;
        }

        logger.info("Server listening on port " + serverSocket.getLocalPort());

        while (running) {
            try {
                Socket sock = serverSocket.accept();
                logger.info(String.format("Connection established: %s", sock.getRemoteSocketAddress()));
                ClientThread clientThread = new ClientThread(sock);
                clientThread.addObserver(this);
                pool.execute(clientThread);
                setChanged();
                notifyObservers(sock);
            } catch (SocketTimeoutException e) {
                // Check if the current thread has been interrupted
                if (Thread.currentThread().isInterrupted()) {
                    stop();
                    setChanged();
                    notifyObservers();
                }
            } catch (IOException e) {
                if (running) {
                    logger.log(Level.WARNING, "I/O error when handling client connection request", e);
                }
            }
        }
    }

    public void stop() {
        if (!running)
            return;
        try {
            logger.info("Shutting down server...");
            running = false;
            serverSocket.close();
            pool.shutdown(); // Disable new tasks from being submitted
            // Wait a while for existing tasks to terminate
            if (!pool.awaitTermination(100, TimeUnit.MILLISECONDS)) {
                pool.shutdownNow(); // Cancel currently executing tasks
                // Wait a while for tasks to respond to being cancelled
                if (!pool.awaitTermination(100, TimeUnit.MILLISECONDS))
                    logger.severe("Pool did not terminate");
            }
            logger.info("Server shutdown complete");
        } catch (IOException | InterruptedException e) {
            logger.log(Level.WARNING, "Server interrupted while shutting down", e);
            // (Re-)Cancel if current thread also interrupted
            pool.shutdownNow();
            // Preserve interrupt status
            Thread.currentThread().interrupt();
        }
    }

    @Override
    public void update(Observable o, Object arg) {
        if (o instanceof ClientThread) {
            setChanged();
            notifyObservers();
        }
    }

}
