import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame {
    private final int X = 200;
    private final int Y = 200;
    private final int WIDTH = 500;
    private final int HEIGHT = 200;
    private MyListener manager;

    public MyFrame(String titolo) {
        super(titolo);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setBounds(X, Y, WIDTH, HEIGHT);
        this.setResizable(false);

        Container cont = this.getContentPane();
        cont.setLayout(new BorderLayout());

        // Pannello principale
        JPanel main = new JPanel(new GridLayout(2, 2));
        
        JPanel matricola = new JPanel(new GridLayout(2, 1));
        JLabel lbl_matricola = new JLabel("Matricola");
        JTextField txt_matricola = new JTextField();
        matricola.add(lbl_matricola);
        matricola.add(txt_matricola);

        JPanel address = new JPanel(new GridLayout(2, 1));
        JLabel lbl_address = new JLabel("IP Address");
        JTextField txt_address = new JTextField();
        address.add(lbl_address);
        address.add(txt_address);

        JPanel port = new JPanel(new GridLayout(2, 1));
        JLabel lbl_port = new JLabel("Porta");
        JTextField txt_port = new JTextField();
        port.add(lbl_port);
        port.add(txt_port);

        main.add(matricola);
        main.add(address);
        main.add(port);

        cont.add(main, BorderLayout.CENTER);

        // Pannello pulsanti
        JPanel pulsanti = new JPanel();

        JButton connect = new JButton("Connect");

        JButton disconnect = new JButton("Disconnect");
        disconnect.setEnabled(false);

        JButton start = new JButton("Start");
        start.setEnabled(false);
        
        JButton stop = new JButton("Stop");
        stop.setEnabled(false);

        manager = new MyListener(connect, disconnect, start, stop, txt_address, txt_port);
        connect.addActionListener(manager);
        disconnect.addActionListener(manager);
        start.addActionListener(manager);
        stop.addActionListener(manager);

        pulsanti.add(connect);
        pulsanti.add(disconnect);
        pulsanti.add(start);
        pulsanti.add(stop);

        cont.add(pulsanti, BorderLayout.SOUTH);

        this.setVisible(true);
    }
}
