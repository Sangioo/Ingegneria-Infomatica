package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.*;

public class MyListener implements ActionListener {

    public static final String CONNECT = "CONNECT";
    public static final String DISCONNECT = "DISCONNECT";
    public static final String START = "START";
    public static final String STOP = "STOP";

    public boolean connected = false;
    public boolean transmitting = false;

    private final MyFrame frame;
    private final JTextField txtAddress;
    private final JTextField txtPort;
    private final JTextArea areaIta;
    private final JTextArea areaUsa;
    private final JTextArea areaLog;

    private Socket sock = null;
    private Scanner inputScanner;
    private PrintWriter outputWriter;

    public MyListener(MyFrame frame) {
        this.frame = frame;
        this.txtAddress = frame.getTxtAddress();
        this.txtPort = frame.getTxtPort();
        this.areaIta = frame.getAreaIta();
        this.areaUsa = frame.getAreaUsa();
        this.areaLog = frame.getAreaLog();
    }

    public void startConnection(String address, String port) throws IOException {
        this.sock = new Socket(address, Integer.parseInt(port));
        this.inputScanner = new Scanner(this.sock.getInputStream());
        this.outputWriter = new PrintWriter(this.sock.getOutputStream());
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals(CONNECT)) {
            connect();
        } else if (e.getActionCommand().equals(DISCONNECT)) {
            disconnect();
        } else if (e.getActionCommand().equals(START)) {
            start();
        } else if (e.getActionCommand().equals(STOP)) {
            stop();
        }
        frame.enableButtons(connected, transmitting);
    }

    private void connect() {
        try {
            this.startConnection(txtAddress.getText(), txtPort.getText());
            this.connected = true;
        } catch (IOException err0) {
            JOptionPane.showMessageDialog(frame, "Connessione fallita!");
        } catch (NumberFormatException err1) {
            JOptionPane.showMessageDialog(frame, "La porta deve essere un numero intero");
        }
        areaIta.setText("");
        areaUsa.setText("");
        areaLog.setText("");
    }

    private void disconnect() {
        this.outputWriter.println("DISCONNECT");
        this.outputWriter.flush();
        this.outputWriter.close();
        this.inputScanner.close();
        try {
            this.sock.close();
        } catch (IOException err) {
            err.printStackTrace();
        }
        this.connected = false;
    }

    private void start() {
        this.outputWriter.println("START");
        this.outputWriter.flush();
        Thread t = new Thread(new Downloader(inputScanner, frame, this));
        t.start();
        this.transmitting = true;
    }

    private void stop() {
        this.outputWriter.println("STOP");
        this.outputWriter.flush();
        this.transmitting = false;
    }
}

