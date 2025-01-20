package client;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
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
				break;
				
			case "Disconnect":
				disconnect();
				break;
				
			case "Start":
				start(finestra.getNumeri());
				break;
				
			case "Interrompi":
				stop();
				break;
			
			case "Clear":
				clear();
				break;
			
			default:
				JOptionPane.showMessageDialog(finestra, "Comando non riconosciuto");
		}
	}

	private void clear() {
		finestra.resetColori();
		finestra.resetNumeri();
	}

	private void stop() {
		output.println("interrompi");
		output.flush();
	}

	private void start(String[] numeri) {
		for (String num : numeri) {
			if (num.isBlank()) {
				JOptionPane.showMessageDialog(finestra, "Tutte le caselle devono essere riempite");
				return;
			}
		}
		
		finestra.resetColori();
		finestra.setPulsanti(true, true);
		output.println("start");
		output.flush();
		
		Thread download = new Thread(new Downloader(input, finestra));
		download.start();
	}

	private void disconnect() {
		try {
			output.println("disconnect");
			output.flush();
			input.close();
			output.close();
			sock.close();
			finestra.setPulsanti(false, false);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(finestra, "Errore di disconnessione");
		}
	}

	private void connect(String address, String porta) {
		try {
			sock = new Socket(address, Integer.parseInt(porta));
			input = new Scanner(sock.getInputStream());
			output = new PrintWriter(sock.getOutputStream());
			finestra.setPulsanti(true, false);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(finestra, "Errore di connessione");
		}
	}
}
