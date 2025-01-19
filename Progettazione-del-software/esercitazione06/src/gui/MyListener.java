package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

import javax.swing.JOptionPane;

public class MyListener implements ActionListener {
	private MyFrame finestra;
	private Downloader downloader;
	private Thread downloadThread;
	
	private Socket sock = null;
	private Scanner input;
	private PrintWriter output;
	
	private String address, porta;
	
	public MyListener(MyFrame finestra) {
		this.finestra = finestra;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		String comando = e.getActionCommand();
		if (comando.equals("Connect")) {
			address = finestra.getAddress();
			porta = finestra.getPorta();
			connect(address, porta);
		} else if (comando.equals("Disconnect")) {
			disconnect();
		} else if (comando.equals("Start")) {
			start();
		} else if (comando.equals("Stop")) {
			stop();
		}
	}

	public void connect(String address, String porta) {
		try {
			int intPorta = Integer.parseInt(porta);
			sock = new Socket(address, intPorta);
			input = new Scanner(sock.getInputStream());
			output = new PrintWriter(sock.getOutputStream());
			
			finestra.setAreaUsa("");
			finestra.setAreaIta("");
			finestra.setAreaLog("");
			
			finestra.setPulsanti(true, false);
		} catch (UnknownHostException e) {
			JOptionPane.showMessageDialog(finestra, "HOST NON TROVATO");
		} catch (IOException e) {
			JOptionPane.showMessageDialog(finestra, "CONNESSIONE NON RIUSCITA");
		}
	}
	
	public void disconnect() {
		this.output.println("DISCONNECT");
		this.output.flush();
		try {
			sock.close();
			input.close();
			output.close();
			finestra.setPulsanti(false, false);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(finestra, "DISCONNESSIONE NON RIUSCITA");
		}
	}
	
	public void start() {
		this.output.println("START");
		this.output.flush();
		
		downloadThread = new Thread(new Downloader(finestra, input));
		downloadThread.start();
		
		this.finestra.setPulsanti(true, true);
	}
	
	public void stop() {
		this.output.println("STOP");
		this.output.flush();
		
		this.finestra.setPulsanti(true, false);
	}
}
