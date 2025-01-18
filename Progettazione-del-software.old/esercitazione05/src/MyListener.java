import java.awt.event.*;
import javax.swing.*;

public class MyListener implements ActionListener {
    private JButton bconnect;
    private JButton bdisconnect;
    private JButton bstart;
    private JButton bstop;
    private JTextField address;
    private JTextField port;

    public MyListener(JButton bconnect, JButton bdisconnect, JButton bstart, JButton bstop, JTextField address, JTextField port) {
        this.bconnect = bconnect;
        this.bdisconnect = bdisconnect;
        this.bstart = bstart;
        this.bstop = bstop;
        this.address = address;
        this.port = port;
    }

    public void actionPerformed(ActionEvent e) {
        JButton button = (JButton) e.getSource();
        
        switch (button.getText()) {
            case "Connect":
                connect();
                break;
            case "Disconnect":
                disconnect();
                break;
            case "Start":
                start();
                break;
            case "Stop":
                stop();
                break;
        
            default:
                break;
        }
    }

    void connect() {
        bconnect.setEnabled(false);
        bdisconnect.setEnabled(true);
        bstart.setEnabled(true);
        bstop.setEnabled(false);
        System.out.println("connect " + address.getText() + ":" + port.getText());
    }

    void disconnect() {
        bconnect.setEnabled(true);
        bdisconnect.setEnabled(false);
        bstart.setEnabled(false);
        bstop.setEnabled(false);
        System.out.println("disconnect");
    }

    void start() {
        bconnect.setEnabled(false);
        bdisconnect.setEnabled(true);
        bstart.setEnabled(false);
        bstop.setEnabled(true);
        System.out.println("start");
    }

    void stop() {
        bconnect.setEnabled(false);
        bdisconnect.setEnabled(true);
        bstart.setEnabled(true);
        bstop.setEnabled(false);
        System.out.println("stop");
    }
}
