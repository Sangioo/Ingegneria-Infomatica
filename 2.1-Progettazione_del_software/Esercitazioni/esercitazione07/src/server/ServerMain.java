package server;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ServerMain {
    private static final String logFormat = "%1$tY-%1$tm-%1$td %1$tH:%1$tM:%1$tS %4$-6s [%2$s] %5$s%6$s%n";

    private static void runServerCLI(int port) {
        ExecutorService executor = Executors.newSingleThreadExecutor();
        executor.execute(new ServerThread(port));
    }

    private static void runServerGUI() {
        ServerFrame gm = new ServerFrame();
    }

    public static void main(String[] args) {
        // Set logger format
        System.setProperty("java.util.logging.SimpleFormatter.format", logFormat);

        boolean useGui = true;
        int port = 4400;

        // Process command line arguments
        for (String arg : args) {
            if (arg.equalsIgnoreCase("-nogui")) {
                useGui = false;
            } else { // assume its a port number
                try {
                    port = Integer.parseInt(arg);
                } catch (NumberFormatException e) {
                    System.err.println("Invalid port number: " + arg);
                    System.exit(1);
                }
            }
        }

        if (useGui) {
            runServerGUI();
        } else {
            runServerCLI(port);
        }
    }

}
