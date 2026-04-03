import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

import javax.swing.JOptionPane;

public class MyListener implements ActionListener {

	private MyFrame finestra;
	private Socket sock;
	private Scanner input;
	private PrintWriter output;

	public MyListener(MyFrame myFrame) {
		this.finestra = myFrame;
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
			start();
			break;
		case "Stop":
			stop();
			break;
		case "Reset":
			reset();
			break;
		case "Randomize":
			randomize();
			break;
		default:
			JOptionPane.showMessageDialog(finestra, "Comando non riconosciuto");
		}
	}

	private void connect(String address, String porta) {
		try {
			sock = new Socket(address, Integer.parseInt(porta));
			input = new Scanner(sock.getInputStream());
			output = new PrintWriter(sock.getOutputStream());
			finestra.setPulsanti(true, false);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(finestra, "Errore connessione");
		} catch (NumberFormatException e) {
			JOptionPane.showMessageDialog(finestra, "Numero porta non valido");
		}
	}

	private void disconnect() {
		try {
			input.close();
			output.close();
			sock.close();
			finestra.setPulsanti(false, false);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(finestra, "Errore disconnessione");
		}
	}

	private void start() {
		for (int i = 0; i < finestra.caselle.length; i++) {
			HashSet<Integer> riga = new HashSet<Integer>();
			for (int j = 0; j < finestra.caselle[0].length; j++) {
				if (!finestra.caselle[i][j].isNumberSelected()) {
					JOptionPane.showMessageDialog(finestra, "Selezionare tutti i numeri");
					return;
				}
				riga.add(Integer.parseInt((String) finestra.caselle[i][j].getSelectedItem()));
			}
			if (riga.size() != finestra.caselle[0].length) {
				JOptionPane.showMessageDialog(finestra, "I numeri devono essere unici nelle righe");
				return;
			}
		}
		
		output.println("start");
		output.flush();
		finestra.setPulsanti(true, true);
		
		for (int i = 0; i < finestra.caselle.length; i++) {
			for (int j = 0; j < finestra.caselle[0].length; j++) {
				finestra.caselle[i][j].setChecked(false);
			}
		}
		
		Thread t = new Thread(new Downloader(finestra, input));
		t.start();
	}

	private void stop() {
		output.println("stop");
		output.flush();
	}

	private void reset() {
		for (int i = 0; i < finestra.caselle.length; i++) {
			for (int j = 0; j < finestra.caselle[0].length; j++) {
				finestra.caselle[i][j].setChecked(false);
				finestra.caselle[i][j].setSelectedIndex(0);
			}
		}
	}

	private void randomize() {
		for (int i = 0; i < finestra.caselle.length; i++) {
			HashSet<Integer> l = new HashSet<Integer>();
			do {				
				l.add((int) Math.floor((Math.random() * 89) + 1));
			} while (l.size() <= 5);
			
			Iterator<Integer> it = l.iterator();
			for (int j = 0; j < finestra.caselle[0].length; j++) {
				finestra.caselle[i][j].setSelectedIndex(it.next());
			}
		}
	}

}
