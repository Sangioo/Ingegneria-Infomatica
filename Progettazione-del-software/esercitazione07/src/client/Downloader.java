package client;

import java.util.Scanner;

import javax.swing.JOptionPane;

public class Downloader implements Runnable {
	private Scanner input;
	private MyFrame finestra;
	private MyListener listener;
	
	public Downloader(Scanner input, MyFrame finestra, MyListener listener) {
		this.input = input;
		this.finestra = finestra;
		this.listener = listener;
	}

	@Override
	public void run() {
		while (true) {
			String riga = input.nextLine();
			
			if (riga.equals("ERROR")) {
				JOptionPane.showMessageDialog(finestra, "Errore nella comunicazione");
				listener.disconnect();
				return;
			} else if (riga.equals("END")) {
				finestra.setPulsanti(true, false);
				return;
			} else {
				String[] split = riga.split(":");
				finestra.setLog(finestra.getLog() + riga + "\n");
				finestra.disegna(split[1]);
			}
		}
	}
}
