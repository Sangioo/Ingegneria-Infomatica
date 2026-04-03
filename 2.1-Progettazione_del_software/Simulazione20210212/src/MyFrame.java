import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
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
	private JButton bStart;
	private JButton bStop;
	private JButton bReset;
	private JButton bRandomize;
	public LotteryComboBox[][] caselle = new LotteryComboBox[5][5];

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

		// valori predefiniti
		tAddress.setText("localhost");
		tPorta.setText("4400");

		pConnessione.add(new JLabel("Server Address"));
		pConnessione.add(tAddress);
		pConnessione.add(new JLabel("Port"));
		pConnessione.add(tPorta);
		pConnessione.add(bConnect);
		pConnessione.add(bDisconnect);

		container.add(pConnessione, BorderLayout.NORTH);

		// Pannello ruote
		JPanel pRuote = new JPanel(new GridLayout(5, 6));
		pRuote.setBorder(BorderFactory.createTitledBorder("Lotteria"));
		for (int i = 0; i < 5; i++) {
			pRuote.add(new JLabel("Ruota " + Integer.toString(i + 1)));
			for (int j = 0; j < 5; j++) {
				caselle[i][j] = new LotteryComboBox();
				caselle[i][j].setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
				pRuote.add(caselle[i][j]);
			}
		}
		container.add(pRuote);

		// Pannello controllo
		JPanel pControllo = new JPanel();
		bStart = new JButton("Start");
		bStart.addActionListener(listener);
		bStop = new JButton("Stop");
		bStop.addActionListener(listener);
		bReset = new JButton("Reset");
		bReset.addActionListener(listener);
		bRandomize = new JButton("Randomize");
		bRandomize.addActionListener(listener);

		pControllo.add(bStart);
		pControllo.add(bStop);
		pControllo.add(bReset);
		pControllo.add(bRandomize);

		container.add(pControllo, BorderLayout.SOUTH);

		this.setPulsanti(false, false);
		this.pack();
		this.setResizable(false);
		this.setVisible(true);
	}

	public void setPulsanti(boolean isConnesso, boolean isScaricando) {
		bConnect.setEnabled(!isConnesso);
		bDisconnect.setEnabled(isConnesso && !isScaricando);
		bStart.setEnabled(isConnesso && !isScaricando);
		bStop.setEnabled(isConnesso && isScaricando);
		bReset.setEnabled(isConnesso && !isScaricando);
		bRandomize.setEnabled(isConnesso && !isScaricando);

		if (isConnesso) {
			this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		} else {
			this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		}
		
		for (int i=0; i<5; i++) {
			for (int j=0; j<5; j++) {
				caselle[i][j].setReadOnly(!isConnesso || isScaricando);
			}
		}
	}

	public String getAddress() {
		return tAddress.getText();
	}
	
	public String getPorta() {
		return tPorta.getText();
	}
}
