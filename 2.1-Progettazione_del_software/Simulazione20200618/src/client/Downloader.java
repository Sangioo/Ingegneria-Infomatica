package client;

import java.util.Scanner;

import javax.swing.JOptionPane;

import forniti.Board;

public class Downloader implements Runnable {
	private Board tabella;
	private MyFrame finestra;
	private Scanner input;
	
	public Downloader(Board tabella, MyFrame finestra, Scanner input) {
		this.tabella = tabella;
		this.finestra = finestra;
		this.input = input;
	}

	@Override
	public void run() {
		while(true) {
			String riga = input.nextLine().strip();
			System.out.println(riga);
			if (riga.equals("done")) {
				JOptionPane.showMessageDialog(finestra, "La partita puo' cominciare");
				tabella.setGameActive(true);
				finestra.setPulsanti(true, false);
				return;
			} else if (riga.equals("interrupted")) {
				JOptionPane.showMessageDialog(finestra, "Il download e' stato interrotto");
				tabella.setGameActive(false);
				finestra.setPulsanti(true, false);
				return;
			} else {
				String[] split = riga.split(":");
				int i = Integer.parseInt(split[0]);
				int j = Integer.parseInt(split[1]);
				int count = Integer.parseInt(split[2]);

				if (count == -1) {
					tabella.getButton(i, j).setMine(true);
				} else {
					tabella.getButton(i, j).setAdjacentMinesCount(count);
				}
			}
		}
	}

}
