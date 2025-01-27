import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Font;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class MyFrame extends JFrame {

	private JButton bImmagine1;
	private JButton bImmagine2;
	private JButton bImmagine3;
	private JButton bImmagine4;
	private JButton bImmagine5;
	private JButton bStop;
	private JTextField tAddress;
	private JTextField tPorta;
	private JButton bConnect;
	private JButton bDisconnect;
	private JTextArea textArea;

	public MyFrame(String titolo) {
		super(titolo);
		this.setLocation(200, 100);
		
		this.setLayout(new BorderLayout());
		Container container = this.getContentPane();
		MyListener listener = new MyListener(this);
		
		// Pannello connessione
		JPanel pConnessione = new JPanel();
		tAddress = new JTextField(20);
		tPorta = new JTextField(10);
		bConnect = new JButton("Connect");
		bConnect.addActionListener(listener);
		bDisconnect = new JButton("Disconnect");
		bDisconnect.addActionListener(listener);
		
		//valori predefiniti
		tAddress.setText("localhost");
		tPorta.setText("4400");
		
		pConnessione.add(new JLabel("Server Address"));
		pConnessione.add(tAddress);
		pConnessione.add(new JLabel("Port"));
		pConnessione.add(tPorta);
		pConnessione.add(bConnect);
		pConnessione.add(bDisconnect);
		
		container.add(pConnessione, BorderLayout.NORTH);
		
		textArea = new JTextArea(25,80);
		textArea.setEditable(false);
		textArea.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 18));
		JScrollPane immagine = new JScrollPane(textArea);
		immagine.setBorder(BorderFactory.createTitledBorder("Image"));
		
		container.add(immagine, BorderLayout.CENTER);
		
		// Pannello controllo
		JPanel pControllo = new JPanel();
		bImmagine1 = new JButton("Image 1");
		bImmagine1.addActionListener(listener);
		bImmagine2 = new JButton("Image 2");
		bImmagine2.addActionListener(listener);
		bImmagine3 = new JButton("Image 3");
		bImmagine3.addActionListener(listener);
		bImmagine4 = new JButton("Image 4");
		bImmagine4.addActionListener(listener);
		bImmagine5 = new JButton("Image 5");
		bImmagine5.addActionListener(listener);
		bStop = new JButton("Stop");
		bStop.addActionListener(listener);
		
		pControllo.add(bImmagine1);
		pControllo.add(bImmagine2);
		pControllo.add(bImmagine3);
		pControllo.add(bImmagine4);
		pControllo.add(bImmagine5);
		pControllo.add(bStop);
		
		container.add(pControllo, BorderLayout.SOUTH);
		
		this.setPulsanti(false, false);
		this.pack();
		this.setResizable(false);
		this.setVisible(true);
	}

	public void setPulsanti(boolean isConnesso, boolean isScaricando) {
		bConnect.setEnabled(!isConnesso);
		bDisconnect.setEnabled(isConnesso && !isScaricando);
		bImmagine1.setEnabled(isConnesso && !isScaricando);
		bImmagine2.setEnabled(isConnesso && !isScaricando);
		bImmagine3.setEnabled(isConnesso && !isScaricando);
		bImmagine4.setEnabled(isConnesso && !isScaricando);
		bImmagine5.setEnabled(isConnesso && !isScaricando);
		bStop.setEnabled(isConnesso && isScaricando);
		
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
	
	public void resetArea() {
		textArea.setText("");
	}
	
	public void appendArea(String testo) {
		String buff = textArea.getText();
		textArea.setText(buff + testo + "\n");
	}
}
