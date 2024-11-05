package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.JOptionPane;

public class MyListener implements ActionListener {

    public static final String CONNECT = "CONNECT";
    public static final String DISCONNECT = "DISCONNECT";
    public static final String START = "START";
    public static final String STOP = "STOP";

    public boolean connected = false;
    public boolean transmitting = false;

    private MyFrame frame;

    private Socket sock = null;
    private Scanner inputScanner;
    private PrintWriter outputWriter;

    public MyListener(MyFrame frame) {
        this.frame = frame;
    }

    public void connect(String address, String port) throws IOException {
        this.sock = new Socket(address, Integer.parseInt(port));
        this.inputScanner = new Scanner(this.sock.getInputStream());
        this.outputWriter = new PrintWriter(this.sock.getOutputStream());
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals(CONNECT)) {

            try {
                this.connect(frame.txt_address.getText(), frame.txt_port.getText());
                this.connected = true;
            } catch (IOException err1) {
                JOptionPane.showMessageDialog(frame, "Connessione fallita!");
            } catch (NumberFormatException err2) {
                JOptionPane.showMessageDialog(frame, "La porta deve essere un numero intero");
            }
            this.frame.area_ita.setText("");
            this.frame.area_usa.setText("");
            this.frame.area_log.setText("");

        } else if (e.getActionCommand().equals(DISCONNECT)) {

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

        } else if (e.getActionCommand().equals(START)) {

            this.outputWriter.println("START");
            this.outputWriter.flush();
            Thread t = new Thread(new Downloader(inputScanner, frame, this));
            t.start();
            this.transmitting = true;

        } else if (e.getActionCommand().equals(STOP)) {
            this.outputWriter.println("STOP");
            this.outputWriter.flush();
            this.transmitting = false;
        }
        frame.enableButtons(connected, transmitting);
    }

}

