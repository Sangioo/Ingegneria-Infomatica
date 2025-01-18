package gui;

import javax.swing.*;
import java.util.*;

public class Downloader implements Runnable {

    public static final String END = "END";
    public static final String INTERRUPTED = "INTERRUPTED";
    public static final String START = "START";

    private final Scanner inputScanner;
    private final MyFrame frame;
    private final MyListener listener;
    private final JTextArea areaIta;
    private final JTextArea areaUsa;
    private final JTextArea areaLog;

    private ArrayList<String> arrUsa = new ArrayList<String>();
    private ArrayList<String> arrIta = new ArrayList<String>();

    public Downloader(Scanner s, MyFrame frame, MyListener listener) {
        this.inputScanner = s;
        this.frame = frame;
        this.listener = listener;
        this.areaIta = frame.getAreaIta();
        this.areaUsa = frame.getAreaUsa();
        this.areaLog = frame.getAreaLog();
    }

    @Override
    public void run() {
        while (true) {
            String newLine = this.inputScanner.nextLine();
            System.out.println(newLine);
            if (newLine.equals(END)){
                listener.transmitting = false;
                frame.enableButtons(listener.connected, listener.transmitting);
                break;
            } else if (newLine.equals(INTERRUPTED)){
                listener.transmitting = false;
                frame.enableButtons(listener.connected, listener.transmitting);
                break;
            } else if (!newLine.equals(START)) {
                String[] splitted = newLine.split(":");
                if (splitted[0].equals("USA")) {
                    updateArea(arrUsa, areaUsa, splitted[1]);
                } else if (splitted[0].equals("ITALIA")) {
                    updateArea(arrIta, areaIta, splitted[1]);
                }
                areaLog.setText(areaLog.getText() + newLine + "\n");
            }
        }
    }

    private void updateArea(ArrayList<String> arr, JTextArea area, String city) {
        if (arr.contains(city + "\n")) {
            int index = arr.indexOf(city + "\n");
            arr.set(index, city + " dopp\n");
        } else if (!arr.contains(city + " dopp\n")) {
            arr.add(city + "\n");
        }

        StringBuffer sb = new StringBuffer();
        for (String elem : arr) { sb.append(elem); }
        area.setText(sb.toString());
    }
}

