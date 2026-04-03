package client;

import java.util.Scanner;

import javax.swing.JOptionPane;

public class Downloader implements Runnable {
	private Scanner input;
	private MyFrame finestra;
	
	public Downloader(Scanner input, MyFrame finestra) {
		this.input = input;
		this.finestra = finestra;
	}

	@Override
	public void run() {
		while (true) {
			String riga = input.nextLine();
			
			if (riga.equals("*;*")) {
				if (finestra.vittoria()) {
					JOptionPane.showMessageDialog(finestra, "Congratulazioni, ha vinto l'utente!");
				} else {
					JOptionPane.showMessageDialog(finestra, "Mi dispiace, ha vinto il server");
				}
				finestra.setPulsanti(true, false);
				return;
			} else if (riga.equals("-1;-1")) {
				JOptionPane.showMessageDialog(finestra, "Mi dispiace, ha vinto il server");
				finestra.setPulsanti(true, false);
				return;
			} else {
				String[] split = riga.split(";");
				finestra.setCasella(Integer.parseInt(split[0]), split[1]);
			}
		}
	}
}
