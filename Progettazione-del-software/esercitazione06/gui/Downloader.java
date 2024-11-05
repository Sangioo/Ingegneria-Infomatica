package gui;

import java.util.Scanner;

public class Downloader implements Runnable {

    private Scanner inputScanner;
    private MyFrame frame;
    private MyListener listener;

    public Downloader(Scanner s, MyFrame frame, MyListener listener) {
        this.inputScanner = s;
        this.frame = frame;
        this.listener = listener;
    }

    @Override
    public void run() {
        while (true) {
            String newLine = this.inputScanner.nextLine();
            System.out.println(newLine);
            if (newLine.equals("END")) {
                listener.transmitting = false;
                frame.enableButtons(listener.connected, listener.transmitting);
                break;
            } else if (newLine.equals("INTERRUPTED")) {
                listener.transmitting = false;
                frame.enableButtons(listener.connected, listener.transmitting);
                break;
            } else if (!newLine.equals("START")) {
                String[] splitted = newLine.split(":");
                if (splitted[0].equals("USA")) {
                    if (frame.area_usa.getText().contains(splitted[1])) {
                        frame.area_usa.setText(frame.area_usa.getText() + splitted[1] + " dopp\n");
                    } else {
                        frame.area_usa.setText(frame.area_usa.getText() + splitted[1] + "\n");
                    }
                } else if (splitted[0].equals("ITALIA")) {
                    if (frame.area_ita.getText().contains(splitted[1])) {
                        frame.area_ita.setText(frame.area_ita.getText() + splitted[1] + " dopp\n");
                    } else {
                        frame.area_ita.setText(frame.area_ita.getText() + splitted[1] + "\n");
                    }
                }
                frame.area_log.setText(frame.area_log.getText() + newLine + "\n");
            }
        }
    }

}

