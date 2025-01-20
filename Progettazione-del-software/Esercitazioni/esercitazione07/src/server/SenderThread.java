package server;

import java.io.PrintWriter;
import java.util.List;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Implementation of {@code Runnable} that produces the messages for the client.
 */
public class SenderThread implements Runnable {
    private static final Logger logger = Logger.getLogger(SenderThread.class.getName());
    private boolean finished;
    private boolean interrupted;
    private final List<String> lines;
    private final PrintWriter pw;

    public SenderThread(PrintWriter pw, List<String> lines) {
        this.pw = pw;
        this.lines = lines;
    }

    @Override
    public void run() {
        try {
            for (String line : lines) {
                // Wait some time for the next message
                TimeUnit.MILLISECONDS.sleep(4000);
                // Check if this thread has been interrupted
                if (Thread.currentThread().isInterrupted()) {
                    throw new InterruptedException();
                }
                // Check if the thread has been stopped
                if (finished)
                    break;
                pw.println(line);
                pw.flush();
            }
            logger.log(Level.INFO, "Sent all rows");
            finished = true;
        } catch (InterruptedException e) {
            logger.log(Level.WARNING, "Sender thread interrupted");
            stop();
        } finally {
            pw.println(interrupted ? "INTERRUPTED" : "END");
            pw.flush();
        }
    }

    public void stop() {
        if (!finished) {
            finished = true;
            interrupted = true;
        }
    }

}
