package client;

import java.awt.BorderLayout;
import java.awt.Container;
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
	private JTextField tAddress, tPorta;
	private JButton bConnect, bDisconnect, bStart, bStop;
	private JTextArea areaUsa, areaIta, areaLog;

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
		JPanel pCentrale = new JPanel(new GridLayout(1,3));
		areaUsa = new JTextArea(10,25);
		JScrollPane scrollUsa = new JScrollPane(areaUsa);
		scrollUsa.setBorder(BorderFactory.createTitledBorder("USA"));
		
		areaIta = new JTextArea(10,25);
		JScrollPane scrollIta = new JScrollPane(areaIta);
		scrollIta.setBorder(BorderFactory.createTitledBorder("Italia"));
		
		areaLog = new JTextArea(10,25);
		JScrollPane scrollLog = new JScrollPane(areaLog);
		scrollLog.setBorder(BorderFactory.createTitledBorder("Log"));
		
		pCentrale.add(scrollUsa);
		pCentrale.add(scrollIta);
		pCentrale.add(scrollLog);
		
		container.add(pCentrale, BorderLayout.CENTER);
		
		//Pannello sud
		JPanel pSud = new JPanel();
		bStart = new JButton("Start");
		bStop = new JButton("Stop");
		
		bStart.addActionListener(listener);
		bStop.addActionListener(listener);
		
		pSud.add(bStart);
		pSud.add(bStop);
		
		container.add(pSud, BorderLayout.SOUTH);
		
		setPulsanti(false, false);
		this.setVisible(true);
		this.pack();
		this.setResizable(false);
	}

	public void setAreaUsa(String text) {
		this.areaUsa.setText(text);
	}
	
	public void setAreaIta(String text) {
		this.areaIta.setText(text);
	}
	
	public void setAreaLog(String text) {
		this.areaLog.setText(text);
	}
	
	public String getAreaUsa() {
		return areaUsa.getText();
	}

	public String getAreaIta() {
		return areaIta.getText();
	}

	public String getAreaLog() {
		return areaLog.getText();
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
			this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		} else if (isConnesso && !isTrasmettendo) {
			this.bConnect.setEnabled(false);
			this.bDisconnect.setEnabled(true);
			this.bStart.setEnabled(true);
			this.bStop.setEnabled(false);
			this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		} else if (!isConnesso && !isTrasmettendo) {
			this.bConnect.setEnabled(true);
			this.bDisconnect.setEnabled(false);
			this.bStart.setEnabled(false);
			this.bStop.setEnabled(false);
			this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		}
	}
}
