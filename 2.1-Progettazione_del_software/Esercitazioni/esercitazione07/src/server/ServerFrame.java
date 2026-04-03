package server;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.text.AbstractDocument;
import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.DocumentFilter;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.util.Observable;
import java.util.Observer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.logging.Handler;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.LogRecord;
import java.util.logging.SimpleFormatter;

/**
 * Graphical user interface to manage the server instance.
 */
public class ServerFrame extends JFrame implements Observer, ActionListener {
    private static final int LOG_SIZE = 1000;
    private JButton startButton;
    private JButton stopButton;
    private JButton clearButton;
    private JTextField portField;
    private JLabel portLabel;
    private JLabel clientsLabel;
    private JTextArea logArea;
    private ServerThread serverThread;
    private ExecutorService executor;

    public ServerFrame() {
        super("Lab Server");

        // Widgets
        startButton = new JButton("Start");
        startButton.setMnemonic(KeyEvent.VK_S);
        stopButton = new JButton("Stop");
        stopButton.setMnemonic(KeyEvent.VK_T);
        clearButton = new JButton("Clear Log");
        clearButton.setMnemonic(KeyEvent.VK_C);
        portField = new JTextField(10);
        portLabel = new JLabel("Port");
        portField.setText("4400");
        clientsLabel = new JLabel("Active Clients: 0");
        logArea = new JTextArea(25, 80);
        logArea.setEditable(false);
        ((AbstractDocument)logArea.getDocument()).setDocumentFilter(new LogDocumentFilter(LOG_SIZE));

        // Layout
        JPanel topPanel = new JPanel(new BorderLayout());
        JPanel confPanel = new JPanel();
        JPanel logPanel = new JPanel(new BorderLayout());
        confPanel.add(startButton);
        confPanel.add(stopButton);
        confPanel.add(portLabel);
        confPanel.add(portField);
        confPanel.add(clearButton);
        topPanel.add(confPanel, BorderLayout.WEST);
        topPanel.add(clientsLabel, BorderLayout.EAST);
        topPanel.setBorder(BorderFactory.createTitledBorder("Server Configuration"));
        logPanel.add(new JScrollPane(logArea), BorderLayout.CENTER);
        logPanel.setBorder(BorderFactory.createTitledBorder("Log Area"));

        add(topPanel, BorderLayout.NORTH);
        add(logPanel, BorderLayout.CENTER);

        // Listeners
        startButton.setActionCommand("start");
        startButton.addActionListener(this);
        stopButton.setActionCommand("stop");
        stopButton.addActionListener(this);
        clearButton.setActionCommand("clear");
        clearButton.addActionListener(this);

        // Initial state
        stopButton.setEnabled(false);

        // Publish logs into the log text area
        LogManager.getLogManager().getLogger("").addHandler(new LogHandler());
        executor = Executors.newSingleThreadExecutor();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    @Override
    public void update(Observable o, Object arg) {
        if (o instanceof ServerThread) {
            ServerThread server = (ServerThread) o;
            SwingUtilities.invokeLater(() -> this.clientsLabel.setText("Active Clients: " + server.getClientCount()));
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();
        // Happens on EDT, so it must execute in a very short amount of time
        if (cmd.equals("start")) {
            try {
                serverThread = new ServerThread(Integer.parseInt(portField.getText()));
                serverThread.addObserver(this);
                executor.execute(serverThread);
                startButton.setEnabled(false);
                stopButton.setEnabled(true);
                setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Formato porta errato", "Errore", JOptionPane.ERROR_MESSAGE);
            }
        } else if (cmd.equals("stop")) {
            try {
                serverThread.stop();
                executor.awaitTermination(100, TimeUnit.MILLISECONDS);
                startButton.setEnabled(true);
                stopButton.setEnabled(false);
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        } else if (cmd.equals("clear")) {
            SwingUtilities.invokeLater(() -> { logArea.setText(""); });
        }
    }

    /**
     * Implementation of a {@code DocumentFilter} that truncates the text area
     * text to keep it within a fixed amount of lines.
     */
    private class LogDocumentFilter extends DocumentFilter {
        private int maxLines;

        LogDocumentFilter(int maxLines) {
            this.maxLines = maxLines;
        }

        @Override
        public void insertString(FilterBypass fb, int offset, String string, AttributeSet attr)
                throws BadLocationException {
            super.insertString(fb, offset, string, attr);
            truncate(fb);
        }

        @Override
        public void replace(FilterBypass fb, int offset, int length,
                            String text, AttributeSet attrs) throws BadLocationException {
            super.replace(fb, offset, length, text, attrs);
            truncate(fb);
        }

        private void truncate(FilterBypass fb) throws BadLocationException {
            int lines = logArea.getLineCount();
            if (lines > maxLines) {
                int linesToRemove = lines - maxLines -1;
                int lengthToRemove = logArea.getLineStartOffset(linesToRemove);
                remove(fb, 0, lengthToRemove);
            }
        }
    }

    /**
     * Implementation of {@code Handler} that publishes records into a text area.
     */
    private class LogHandler extends Handler {
        LogHandler() {
            setFormatter(new SimpleFormatter());
            setLevel(Level.ALL);
        }

        @Override
        public void publish(LogRecord record) {
            if (!isLoggable(record))
                return;
            String msg = getFormatter().format(record);
            SwingUtilities.invokeLater(() -> {
                logArea.append(msg);
                logArea.setCaretPosition(logArea.getText().length());
            });
        }

        @Override
        public void flush() { }

        @Override
        public void close() throws SecurityException { }
    }

}
