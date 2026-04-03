package client;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.JOptionPane;

import forniti.Board;

public class MyListener implements ActionListener {
	private MyFrame finestra;
	private Socket sock;
	private Scanner input;
	private PrintWriter output;
	private Board tabella;
	
	public MyListener(MyFrame finestra, Board tabella) {
		this.finestra = finestra;
		this.tabella = tabella;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		switch (e.getActionCommand()) {
		case "Connect":
			connect(finestra.getAddress(), finestra.getPorta());
			break;

		case "Disconnect":
			disconnect();
			break;
			
		case "Start":
			start();
			break;
		
		case "Stop":
			stop();
			break;
			
		case "Rivela":
			rivela();
			break;
		
		default:
			JOptionPane.showMessageDialog(finestra, "Comando non riconosciuto");
		}
	}

	private void rivela() {
		tabella.revealBoard();
		tabella.setGameActive(false);
	}

	private void stop() {
		output.println("stop");
		output.flush();
	}

	private void start() {
		output.println("start");
		output.flush();
		finestra.setPulsanti(true, true);
		tabella.resetGame();
		
		Thread download = new Thread(new Downloader(tabella, finestra, input));
		download.start();
	}

	private void disconnect() {
		try {
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
		} catch (NumberFormatException e) {
			JOptionPane.showMessageDialog(finestra, "Numero di porta non valido");
		}
	}

}
