package gui;

import java.awt.*;
import javax.swing.*;

public class MyFrame extends JFrame {

    public JTextField txt_address = new JTextField(15);
    public JTextField txt_port = new JTextField(16);
    public JButton b_connect = new JButton("Connect");
    public JButton b_disconnect = new JButton("Disconnect");

    public JButton b_start = new JButton("Start");
    public JButton b_stop = new JButton("Stop");

    public JTextArea area_usa = new JTextArea(10, 25);
    public JTextArea area_ita = new JTextArea(10, 25);
    public JTextArea area_log = new JTextArea(10, 25);

    public MyFrame() {
        super("Andrea Sangiovanni 2108098");

        MyListener listener = new MyListener(this);

        Container container = this.getContentPane();
        container.setLayout(new BorderLayout());

        //North panel
        JPanel p_nord = new JPanel();

        p_nord.add(new JLabel("Server Address"));

        txt_address.setText("94.177.218.70");
        p_nord.add(txt_address);

        txt_port.setText("4400");
        p_nord.add(new JLabel("Port"));
        p_nord.add(txt_port);

        b_connect.setActionCommand(MyListener.CONNECT);
        b_connect.addActionListener(listener);
        p_nord.add(b_connect);

        b_disconnect.setActionCommand(MyListener.DISCONNECT);
        b_disconnect.addActionListener(listener);
        p_nord.add(b_disconnect);

        container.add(p_nord, BorderLayout.NORTH);

        //South panel
        JPanel p_sud = new JPanel();

        b_start.setActionCommand(MyListener.START);
        b_start.addActionListener(listener);
        p_sud.add(b_start);

        b_stop.setActionCommand(MyListener.STOP);
        b_stop.addActionListener(listener);
        p_sud.add(b_stop);

        container.add(p_sud, BorderLayout.SOUTH);

        //Central panel
        JPanel p_centro = new JPanel();

        area_usa.setEditable(false);
        JScrollPane pane_usa = new JScrollPane(area_usa);
        pane_usa.setBorder(BorderFactory.createTitledBorder("USA"));
        p_centro.add(pane_usa);

        area_ita.setEditable(false);
        JScrollPane pane_ita = new JScrollPane(area_ita);
        pane_ita.setBorder(BorderFactory.createTitledBorder("Italia"));
        p_centro.add(pane_ita);

        area_log.setEditable(false);
        JScrollPane pane_log = new JScrollPane(area_log);
        pane_log.setBorder(BorderFactory.createTitledBorder("Log"));
        p_centro.add(pane_log);

        container.add(p_centro, BorderLayout.CENTER);

        //Frame settings
        this.enableButtons(false, false);
        this.pack();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocation(300, 300);
        this.setResizable(false);
        this.setVisible(true);
    }

    public void enableButtons(boolean connected, boolean transmitting) {
        b_connect.setEnabled(!connected && !transmitting);
        b_disconnect.setEnabled(connected && !transmitting);
        b_start.setEnabled(connected && !transmitting);
        b_stop.setEnabled(connected && transmitting);
        this.setDefaultCloseOperation(connected ? JFrame.DO_NOTHING_ON_CLOSE : JFrame.EXIT_ON_CLOSE);
    }
}

