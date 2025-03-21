package server;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
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
    private Map<Integer, String> daInviare;
    Random rand;
    int upperbound;

    public ClientThread(Socket sock) throws FileNotFoundException {
        this.sock = Objects.requireNonNull(sock, "Client socket must not be null");
        this.executor = Executors.newSingleThreadExecutor();
        this.daInviare = new HashMap<>();
        Scanner sc = new Scanner(getClass().getResourceAsStream("elenco.txt"));
        while(sc.hasNext()){
            String line = sc.nextLine();
            String[] tokens = line.split(":");
            int num = Integer.valueOf(tokens[0]);
            daInviare.put(num, tokens[1]);
        }
        rand = new Random();
        upperbound = daInviare.size();
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
                logger.info("Received: " + cmd.substring(0, Math.min(cmd.length(), 100)));
                
                //DA QUI MODIFICARE
                if (cmd.contains("GET")){
                    String[] tokens = cmd.split(":");
                    List<String> toSend = new ArrayList<>();
                    
                    try{
                        int i = Integer.parseInt(tokens[1]);
                    }catch(NumberFormatException nfe){
                        pw.println("ERROR");
                        pw.flush();
                        logger.warning("Client misbehaved, force connection close.");
                        break;
                    }
                    
                    int i = Integer.valueOf(tokens[1]);
                    if (i >= 0 && i <= 9){
                        String message = String.valueOf(i);
                        message = message+":"+daInviare.get(i);
                        toSend.add(message);
                        Collections.shuffle(toSend);
                        st = new SenderThread(pw, toSend);
                        executor.execute(st);
                    } else {
                        pw.println("ERROR");
                        pw.flush();
                        logger.warning("Client misbehaved, force connection close.");
                        break;
                    }
                }else if (cmd.equalsIgnoreCase("DISCONNECT")) {
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