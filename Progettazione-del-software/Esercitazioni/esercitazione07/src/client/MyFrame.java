package client;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class MyFrame extends JFrame {
	private JTextField tAddress, tPorta, tNumero;
	private JButton bConnect, bDisconnect, bGet, bReset;
	private JTextArea areaLog;
	private JButton[] display = new JButton[25];

	public MyFrame(String titolo) {
		super(titolo);
		this.setLocation(200,200);
		
		Container container = this.getContentPane();
		MyListener listener = new MyListener(this);
		
		//Pannello nord
		JPanel pNord = new JPanel();
		JLabel lAddress = new JLabel("Server Address");
		tAddress = new JTextField(20);
		JLabel lPorta = new JLabel("Port");
		tPorta = new JTextField(10);
		bConnect = new JButton("Connect");
		bDisconnect = new JButton("Disconnect");
		
		//valori predefiniti
		tAddress.setText("localhost");
		tPorta.setText("4400");
		
		bConnect.addActionListener(listener);
		bDisconnect.addActionListener(listener);
		
		pNord.add(lAddress);
		pNord.add(tAddress);
		pNord.add(lPorta);
		pNord.add(tPorta);
		pNord.add(bConnect);
		pNord.add(bDisconnect);
		
		container.add(pNord, BorderLayout.NORTH);
		
		//Pannello centrale
		JPanel pCentrale = new JPanel();
		
		JPanel pDisplay = new JPanel(new GridLayout(5,5));
		
		for (int i=0; i<25; i++) {
			display[i] = new JButton();
			display[i].setBackground(Color.WHITE);
			display[i].setEnabled(false);
			display[i].setPreferredSize(new Dimension(100,100));
			pDisplay.add(display[i]);
		}
		pCentrale.add(pDisplay);
		
		areaLog = new JTextArea(10,25);
		JScrollPane scrollLog = new JScrollPane(areaLog);
		scrollLog.setBorder(BorderFactory.createTitledBorder("Log"));
		
		pCentrale.add(scrollLog);
		container.add(pCentrale, BorderLayout.CENTER);
		
		//Pannello sud
		JPanel pSud = new JPanel();
		JLabel lNumero = new JLabel("Numero:");
		tNumero = new JTextField(10);
		bGet = new JButton("Get");
		bReset = new JButton("Reset");
		
		bGet.addActionListener(listener);
		bReset.addActionListener(listener);
		
		pSud.add(lNumero);
		pSud.add(tNumero);
		pSud.add(bGet);
		pSud.add(bReset);
		
		container.add(pSud, BorderLayout.SOUTH);

		setPulsanti(false, false);
		this.setVisible(true);
		this.pack();
		this.setResizable(false);
	}

	public String getAddress() {
		return tAddress.getText();
	}

	public String getPorta() {
		return tPorta.getText();
	}
	
	public String getNumero() {
		return tNumero.getText();
	}
	
	public String getLog() {
		return areaLog.getText();
	}
	
	public void setLog(String log) {
		this.areaLog.setText(log);
	}
	
	public void setNumero(String numero) {
		this.tNumero.setText(numero);
	}
	
	public void setPulsanti(boolean isConnesso, boolean isScaricando) {
		if (isConnesso && isScaricando) {
			this.bConnect.setEnabled(false);
			this.bDisconnect.setEnabled(false);
			this.bGet.setEnabled(false);
			this.bReset.setEnabled(true);
			this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		} else if (isConnesso && !isScaricando) {
			this.bConnect.setEnabled(false);
			this.bDisconnect.setEnabled(true);
			this.bGet.setEnabled(true);
			this.bReset.setEnabled(true);
			this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		} else if (!isConnesso && !isScaricando) {
			this.bConnect.setEnabled(true);
			this.bDisconnect.setEnabled(false);
			this.bGet.setEnabled(false);
			this.bReset.setEnabled(false);
			this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		}
	}
	
	public void resetDisplay() {
		for (int i=0; i<25; i++) {
			display[i].setBackground(Color.WHITE);
		}
	}
	
	public void disegna(String numero) {
		for (int i=0; i<25; i++) {
			if (numero.charAt(i) == '1') {
				display[i].setBackground(Color.BLACK);
			} else {
				display[i].setBackground(Color.WHITE);
			}
		}
	}
}
