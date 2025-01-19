package esercitazione05;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class MyFrame extends JFrame {
	
	private MyListener listener;
	private JTextField tMatricola;
	private JTextField tAddress;
	private JTextField tPorta;
	private JButton bConnect;
	private JButton bDisconnect;
	private JButton bStart;
	private JButton bStop;
	
	public MyFrame(String titolo) {
		super(titolo);
		this.setLocation(200, 200);
		this.setLayout(new BorderLayout());
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		Container container = this.getContentPane();
		
		//Pannello bottoni
		JPanel pBottoni = new JPanel();
		bConnect = new JButton("Connect");
		bDisconnect = new JButton("Disconnect");
		bStart = new JButton("Start");
		bStop = new JButton("Stop");
		
		listener = new MyListener(this);
		
		bConnect.addActionListener(listener);
		bDisconnect.addActionListener(listener);
		bStart.addActionListener(listener);
		bStop.addActionListener(listener);
		
		pBottoni.add(bConnect);
		pBottoni.add(bDisconnect);
		pBottoni.add(bStart);
		pBottoni.add(bStop);
		
		container.add(pBottoni, BorderLayout.SOUTH);
		
		//Pannello centrale
		JPanel pCentrale = new JPanel();
		pCentrale.setLayout(new GridLayout(2,2));
		
		JPanel pMatricola = new JPanel(new GridLayout(2,1));
		JLabel lMatricola = new JLabel("Matricola");
		tMatricola = new JTextField(20);
		pMatricola.add(lMatricola);
		pMatricola.add(tMatricola);
		
		JPanel pAddress = new JPanel(new GridLayout(2,1));
		JLabel lAddress = new JLabel("IP Address");
		tAddress = new JTextField(20);
		pAddress.add(lAddress);
		pAddress.add(tAddress);
		
		JPanel pPorta = new JPanel(new GridLayout(2,1));
		JLabel lPorta = new JLabel("Porta");
		tPorta = new JTextField(20);
		pPorta.add(lPorta);
		pPorta.add(tPorta);
		
		pCentrale.add(pMatricola);
		pCentrale.add(pAddress);
		pCentrale.add(pPorta);
		
		container.add(pCentrale, BorderLayout.CENTER);
		
		setPulsanti(false, false);
		this.setVisible(true);
		this.pack();
		this.setResizable(false);
	}

	public String getMatricola() {
		return tMatricola.getText();
	}

	public String getAddress() {
		return tAddress.getText();
	}

	public String getPorta() {
		return tPorta.getText();
	}
	
	public void setPulsanti(boolean isConnesso, boolean isTrasmettendo) {
		if (isConnesso && isTrasmettendo) {
			this.bConnect.setEnabled(false);
			this.bDisconnect.setEnabled(false);
			this.bStart.setEnabled(false);
			this.bStop.setEnabled(true);
		} else if (isConnesso && !isTrasmettendo) {
			this.bConnect.setEnabled(false);
			this.bDisconnect.setEnabled(true);
			this.bStart.setEnabled(true);
			this.bStop.setEnabled(false);
		} else if (!isConnesso && !isTrasmettendo) {
			this.bConnect.setEnabled(true);
			this.bDisconnect.setEnabled(false);
			this.bStart.setEnabled(false);
			this.bStop.setEnabled(false);
		}
	}
}
