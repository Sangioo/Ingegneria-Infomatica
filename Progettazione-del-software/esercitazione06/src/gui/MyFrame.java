package gui;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class MyFrame extends JFrame {
	private JTextField tAddress;
	private JTextField tPorta;
	private JButton bConnect;
	private JButton bDisconnect;

	public MyFrame(String titolo) {
		super(titolo);
		this.setLocation(200,200);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		Container container = this.getContentPane();
		MyListener listener = new MyListener();
		
		//Pannello nord
		JPanel pNord = new JPanel();
		JLabel lAddress = new JLabel("Server Address");
		tAddress = new JTextField(15);
		JLabel lPorta = new JLabel("Port");
		tPorta = new JTextField(5);
		bConnect = new JButton("Connect");
		bDisconnect = new JButton("Disconnect");
		
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
		
		
		this.setVisible(true);
		this.pack();
		this.setResizable(false);
	}
}
