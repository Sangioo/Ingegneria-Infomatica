package gui;

import java.awt.*;
import javax.swing.*;

public class MyFrame extends JFrame {

    private final JTextField txtAddress = new JTextField(15);
    private final JTextField txtPort = new JTextField(16);
    private final JButton bConnect = new JButton("Connect");
    private final JButton bDisconnect = new JButton("Disconnect");

    private final JButton bStart = new JButton("Start");
    private final JButton bStop = new JButton("Stop");

    private final JTextArea areaUsa = new JTextArea(10, 25);
    private final JTextArea areaIta = new JTextArea(10, 25);
    private final JTextArea areaLog = new JTextArea(10, 25);

    public MyFrame() {
        super("Andrea Sangiovanni 2108098");

        MyListener listener = new MyListener(this);

        Container container = this.getContentPane();
        container.setLayout(new BorderLayout());

        //North panel
        JPanel p_nord = new JPanel();

        p_nord.add(new JLabel("Server Address"));

        txtAddress.setText("localhost");
        p_nord.add(txtAddress);

        txtPort.setText("4400");
        p_nord.add(new JLabel("Port"));
        p_nord.add(txtPort);

        bConnect.setActionCommand(MyListener.CONNECT);
        bConnect.addActionListener(listener);
        p_nord.add(bConnect);

        bDisconnect.setActionCommand(MyListener.DISCONNECT);
        bDisconnect.addActionListener(listener);
        p_nord.add(bDisconnect);

        container.add(p_nord, BorderLayout.NORTH);

        //South panel
        JPanel p_sud = new JPanel();

        bStart.setActionCommand(MyListener.START);
        bStart.addActionListener(listener);
        p_sud.add(bStart);

        bStop.setActionCommand(MyListener.STOP);
        bStop.addActionListener(listener);
        p_sud.add(bStop);

        container.add(p_sud, BorderLayout.SOUTH);

        //Central panel
        JPanel p_centro = new JPanel();

        areaUsa.setEditable(false);
        JScrollPane pane_usa = new JScrollPane(areaUsa);
        pane_usa.setBorder(BorderFactory.createTitledBorder("USA"));
        p_centro.add(pane_usa);

        areaIta.setEditable(false);
        JScrollPane pane_ita = new JScrollPane(areaIta);
        pane_ita.setBorder(BorderFactory.createTitledBorder("Italia"));
        p_centro.add(pane_ita);

        areaLog.setEditable(false);
        JScrollPane pane_log = new JScrollPane(areaLog);
        pane_log.setBorder(BorderFactory.createTitledBorder("Log"));
        p_centro.add(pane_log);

        container.add(p_centro, BorderLayout.CENTER);

        //Frame settings
        this.enableButtons(false, false);
        this.pack();
        this.setLocation(300, 300);
        this.setResizable(false);
        this.setVisible(true);
    }

    public void enableButtons(boolean connected, boolean transmitting) {
        bConnect.setEnabled(!connected && !transmitting);
        bDisconnect.setEnabled(connected && !transmitting);
        bStart.setEnabled(connected && !transmitting);
        bStop.setEnabled(connected && transmitting);
        this.setDefaultCloseOperation(connected ? JFrame.DO_NOTHING_ON_CLOSE : JFrame.EXIT_ON_CLOSE);
    }

    public JTextField getTxtAddress() {
        return txtAddress;
    }

    public JTextField getTxtPort() {
        return txtPort;
    }

    public JTextArea getAreaUsa() {
        return areaUsa;
    }

    public JTextArea getAreaIta() {
        return areaIta;
    }

    public JTextArea getAreaLog() {
        return areaLog;
    }
}

