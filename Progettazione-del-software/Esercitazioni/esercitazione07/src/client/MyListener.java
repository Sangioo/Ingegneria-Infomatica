package client;

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
	private Socket sock;
	private Scanner input;
	private PrintWriter output;

	public MyListener(MyFrame finestra) {
		this.finestra = finestra;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		switch(e.getActionCommand()) {
		case "Connect":
			connect(finestra.getAddress(), finestra.getPorta());
			reset();
			break;
		case "Disconnect":
			disconnect();
			break;
		case "Get":
			get(finestra.getNumero());
			break;
		case "Reset":
			reset();
			break;
		default:
			JOptionPane.showMessageDialog(finestra, "Opzione non riconosciuta");
		}
	}
	
	public void connect(String address, String porta) {
		try {
			sock = new Socket(address, Integer.parseInt(porta));
			input = new Scanner(sock.getInputStream());
			output = new PrintWriter(sock.getOutputStream());
			finestra.setPulsanti(true, false);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(finestra, "Connessione non riuscita");
		} catch (NumberFormatException e) {
			JOptionPane.showMessageDialog(finestra, "Porta non inserita correttamente");
		}
	}
	
	public void disconnect() {
		try {
			input.close();
			output.close();
			sock.close();
			finestra.setPulsanti(false, false);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(finestra, "Disconnessione non riuscita");
		}
	}
	
	public void get(String numero) {
		try {
			int num = Integer.parseInt(numero);
			if (num < 0 || num > 9) throw new Exception();
		} catch (NumberFormatException e) {
			JOptionPane.showMessageDialog(finestra, "La stringa inserita non e' un numero");
			return;
		} catch (Exception e) {
			JOptionPane.showMessageDialog(finestra, "Il numero deve essere compreso tra 0 e 9 (inclusi)");
			return;
		}
		output.println("GET:" + numero);
		output.flush();
		finestra.resetDisplay();
		
		Thread download = new Thread(new Downloader(input, finestra, this));
		download.start();
		
		finestra.setPulsanti(true, true);
	}
	
	public void reset() {
		finestra.resetDisplay();
		finestra.setLog("");
		finestra.setNumero("");
	}
}
