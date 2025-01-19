package gui;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Downloader implements Runnable {
	private MyFrame finestra;
	private Scanner input;
	private ArrayList<String> righeIta, righeUsa;
	
	public Downloader(MyFrame finestra, Scanner input) {
		this.finestra = finestra;
		this.input = input;
	}

	@Override
	public void run() {
		righeIta = new ArrayList<String>(Arrays.asList(finestra.getAreaIta().split("\n")));
		righeUsa = new ArrayList<String>(Arrays.asList(finestra.getAreaUsa().split("\n")));
		while (true) {
			String riga = this.input.nextLine();
			
			if (riga.equals("INTERRUPTED")) {
				return;
			} else if (riga.equals("END")) {
				this.finestra.setPulsanti(true, false);
				return;
			} else if (!riga.equals("START")) {
				String[] info = riga.split(":");
				aggiungiRiga(info[0], info[1]);
				
				this.finestra.setAreaLog(finestra.getAreaLog() + riga + "\n");
			}
		}
	}

	private void aggiungiRiga(String nazione, String citta) {
		if (nazione.equals("ITALIA")) {
			if (righeIta.contains(citta)) {
				int index = righeIta.indexOf(citta);
				righeIta.set(index, citta + " dopp");
			} else if (righeIta.contains(citta + " dopp")) {
				return;
			} else {
				righeIta.add(citta);
			}
			
			this.finestra.setAreaIta("");
			for (String elem : righeIta) {
				if (elem.equals("")) continue;
				this.finestra.setAreaIta(finestra.getAreaIta() + elem + "\n");					
			}
		} else {			
			if (righeUsa.contains(citta)) {
				int index = righeUsa.indexOf(citta);
				righeUsa.set(index, citta + " dopp");
			} else if (righeUsa.contains(citta + " dopp")) {
				return;
			} else {
				righeUsa.add(citta);
			}
			
			this.finestra.setAreaUsa("");
			for (String elem : righeUsa) {
				if (elem.equals("")) continue;
				this.finestra.setAreaUsa(finestra.getAreaUsa() + elem + "\n");					
			}
		}
	}
}
