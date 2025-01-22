package client;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import forniti.ColoredButton;

public class MyFrame extends JFrame {
	private JButton bStart, bStop, bConnect, bDisconnect, bClear;
	private JTextField tAddress, tPorta;
	private ColoredButton[] bottoni = new ColoredButton[5];
	
	public MyFrame(String titolo) {
		super(titolo);
		this.setBounds(200, 200, 700, 200);
		
		Container container = this.getContentPane();
		MyListener listener = new MyListener(this);
		
		//Pannello nord
		JPanel pNord = new JPanel();
		bStart = new JButton("Start");
		bStart.addActionListener(listener);
		JLabel lAddress = new JLabel("IP Address");
		tAddress = new JTextField(20);
		JLabel lPorta = new JLabel("Porta");
		tPorta = new JTextField(10);
		bStop = new JButton("Interrompi");
		bStop.addActionListener(listener);
		
		//valori predefiniti
		tAddress.setText("localhost");
		tPorta.setText("4400");
		
		pNord.add(bStart);
		pNord.add(lAddress);
		pNord.add(tAddress);
		pNord.add(lPorta);
		pNord.add(tPorta);
		pNord.add(bStop);
		
		container.add(pNord, BorderLayout.NORTH);
		
		//Pannello centrale
		JPanel pCentrale = new JPanel(new GridLayout(1,5));
		for (int i=0; i<bottoni.length; i++) {
			bottoni[i] = new ColoredButton(Integer.toString(i), Color.LIGHT_GRAY);
			pCentrale.add(bottoni[i]);
		}
		container.add(pCentrale, BorderLayout.CENTER);
		
		//Pannello sud
		JPanel pSud = new JPanel();
		bConnect = new JButton("Connect");
		bConnect.addActionListener(listener);
		bDisconnect = new JButton("Disconnect");
		bDisconnect.addActionListener(listener);
		bClear = new JButton("Clear");
		bClear.addActionListener(listener);
		
		pSud.add(bConnect);
		pSud.add(bDisconnect);
		pSud.add(bClear);
		
		container.add(pSud, BorderLayout.SOUTH);
		
		setPulsanti(false, false);
		this.setResizable(false);
		this.setVisible(true);
	}
	
	public String getAddress() {
		return tAddress.getText();
	}
	
	public String getPorta() {
		return tPorta.getText();
	}
	
	public String[] getNumeri() {
		String[] numeri = new String[bottoni.length];
		for (int i=0; i<bottoni.length; i++) {
			numeri[i] = bottoni[i].getDigit();
		}
		
		return numeri;
	}
	
	public void resetColori() {
		for (int i=0; i<bottoni.length; i++) {
			bottoni[i].changeColor(Color.LIGHT_GRAY);
		}
	}
	
	public void resetNumeri() {
		for (int i=0; i<bottoni.length; i++) {
			bottoni[i].setTextDigit("");
		}
	}
	
	public void setPulsanti(boolean isConnesso, boolean isRicevendo) {
		bConnect.setEnabled(!isConnesso);
		bDisconnect.setEnabled(isConnesso && !isRicevendo);
		bStart.setEnabled(isConnesso && !isRicevendo);
		bStop.setEnabled(isConnesso && isRicevendo);
		bClear.setEnabled(!isRicevendo);
		
		if (isConnesso) {
			this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		} else {
			this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		}
		
		if (isRicevendo) {
			for (int i=0; i<bottoni.length; i++)
				bottoni[i].setEnabled(false);
		} else {
			for (int i=0; i<bottoni.length; i++)
				bottoni[i].setEnabled(true);
		}
	}

	public boolean vittoria() {
		for (ColoredButton b : bottoni) {
			if (b.isGreen()) return true;
		}
		return false;
	}
	
	public void setCasella(int posizione, String numero) {
		if (bottoni[posizione].getDigit().equals(numero)) {
			bottoni[posizione].changeColor(Color.GREEN);
		} else {
			bottoni[posizione].changeColor(Color.RED);
		}
	}
}
