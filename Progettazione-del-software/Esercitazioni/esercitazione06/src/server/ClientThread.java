package server;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.Observable;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Implementation of {@code Runnable} that handles requests from a single client.
 */
public class ClientThread extends Observable implements Runnable {
    private static final Logger logger = Logger.getLogger(ClientThread.class.getName());
    private final ExecutorService executor;
    private final Socket sock;
    private SenderThread st;
    private boolean running;
    private List<String> toSend;

    public ClientThread(Socket sock) throws FileNotFoundException {
        this.sock = Objects.requireNonNull(sock, "Client socket must not be null");
        this.executor = Executors.newSingleThreadExecutor();
        this.toSend = new ArrayList<>();
        Scanner sc = new Scanner(getClass().getResourceAsStream("citta.txt"));
        while(sc.hasNext()){
            String line = sc.nextLine();
            toSend.add(line);
        }
    }

    @Override
    public void run() {
        running = true;
        try (Scanner in = new Scanner(sock.getInputStream());
             PrintWriter pw = new PrintWriter(sock.getOutputStream())) {
            while (running) {
                // Check if the current thread has been interrupted
                if (Thread.currentThread().isInterrupted()) {
                    throw new InterruptedException();
                }
                String cmd = in.nextLine();
                logger.info("Received: " + cmd);
                
                //DA QUI MODIFICARE
                if (cmd.equalsIgnoreCase("START")){
                    List<String> toSendClient = new ArrayList<>();
                    toSendClient.add("START");
                    List<String> toSendShuffled = new ArrayList<>(toSend);
                    Collections.shuffle(toSendShuffled);
                    for (String s : toSendShuffled){
                        toSendClient.add(s);
                    }
                    st = new SenderThread(pw, toSendClient);
                    executor.execute(st);
                }else if (cmd.equalsIgnoreCase("STOP") || cmd.equalsIgnoreCase("DISCONNECT")) {
                    if (st != null) {
                        st.stop();
                        executor.awaitTermination(100, TimeUnit.MILLISECONDS);
                    }
                    if (cmd.equalsIgnoreCase("DISCONNECT")) {
                        break;
                    }
                } else {
                    pw.println("ERROR");
                    pw.flush();
                    logger.warning("Client misbehaved, force connection close.");
                    break;
                }
            }
            sock.close();
        } catch (NoSuchElementException e) { // When the connection is closed by the peer
            logger.info("Connection reset by peer " + sock.getRemoteSocketAddress());
        } catch (IOException | InterruptedException e) { // When the connection is closed by the server
            logger.log(Level.WARNING, String.format("Error handling client %s: ", sock.getRemoteSocketAddress()), e);
        } finally {
            stop();
            setChanged();
            notifyObservers(running);
        }
    }

    public void stop() {
        if (!running)
            return;
        try {
            logger.info("Closing connection to " + sock.getRemoteSocketAddress());
            executor.shutdownNow();
            sock.close();
        } catch (IOException e) {
            logger.log(Level.WARNING, "I/O Error closing client socket", e);
        }
        running = false;
    }
    
}