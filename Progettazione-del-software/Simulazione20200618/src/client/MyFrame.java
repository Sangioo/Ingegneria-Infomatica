package client;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import forniti.Board;

public class MyFrame extends JFrame {
	private JTextField tAddress, tPorta;
	private JButton bConnect, bDisconnect, bStart, bStop, bRivela;
	private Board tabella = new Board();

	public MyFrame(String titolo) {
		super(titolo);
		this.setLocation(200, 200);

		Container container = this.getContentPane();
		container.setLayout(new BorderLayout());
		MyListener listener = new MyListener(this, tabella);

		// Pannello di connessione
		JPanel pConnessione = new JPanel();
		tAddress = new JTextField(20);
		tPorta = new JTextField(10);
		bConnect = new JButton("Connect");
		bConnect.addActionListener(listener);
		bDisconnect = new JButton("Disconnect");
		bDisconnect.addActionListener(listener);
		
		// Valori predefiniti
		tAddress.setText("localhost");
		tPorta.setText("4400");

		pConnessione.add(new JLabel("Server Address"));
		pConnessione.add(tAddress);
		pConnessione.add(new JLabel("Port"));
		pConnessione.add(tPorta);
		pConnessione.add(bConnect);
		pConnessione.add(bDisconnect);

		container.add(pConnessione, BorderLayout.NORTH);

		// Pannello di gioco
		container.add(tabella, BorderLayout.CENTER);

		// Pannello di controllo
		JPanel pControllo = new JPanel();
		bStart = new JButton("Start");
		bStart.addActionListener(listener);
		bStop = new JButton("Stop");
		bStop.addActionListener(listener);
		bRivela = new JButton("Rivela");
		bRivela.addActionListener(listener);

		pControllo.add(bStart);
		pControllo.add(bStop);
		pControllo.add(bRivela);

		container.add(pControllo, BorderLayout.SOUTH);

		this.setPulsanti(false, false);
		this.pack();
		this.setResizable(false);
		this.setVisible(true);
	}

	public void setPulsanti(boolean isConnesso, boolean isPreparando) {
		bConnect.setEnabled(!isConnesso);
		bDisconnect.setEnabled(isConnesso && !isPreparando);
		bStart.setEnabled(isConnesso && !isPreparando);
		bStop.setEnabled(isConnesso && isPreparando);
		bRivela.setEnabled(isConnesso && !isPreparando);
		
		if (isConnesso) {
			this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		} else {
			this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		}
	}
	
	public String getAddress() {
		return tAddress.getText();
	}
	
	public String getPorta() {
		return tPorta.getText();
	}
}
