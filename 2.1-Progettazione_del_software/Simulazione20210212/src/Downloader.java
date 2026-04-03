import java.util.Iterator;
import java.util.Scanner;

import javax.swing.JOptionPane;

public class Downloader implements Runnable {

	private MyFrame finestra;
	private Scanner input;

	public Downloader(MyFrame finestra, Scanner input) {
		this.finestra = finestra;
		this.input = input;
	}

	@Override
	public void run() {
		while (true) {
			String riga = input.nextLine();
			
			if (riga.equals("done")) {
				fine();
				break;
			} else if (riga.equals("interrupted")) {
				JOptionPane.showMessageDialog(finestra, "Download interrotto");
				break;
			} else {
				String[] split = riga.split(":");
				int ruota = Integer.parseInt(split[0]) - 1;
				for (int i = 0; i < finestra.caselle[ruota].length; i++) {
					if (finestra.caselle[ruota][i].getSelectedItem().equals(split[1]))
						finestra.caselle[ruota][i].setChecked(true);
				}
			}
		}
		finestra.setPulsanti(true, false);
	}

	private void fine() {
		int[] conta = {0,0,0,0,0};
		for (int i = 0; i < finestra.caselle.length; i++) {
			for (int j = 0; j < finestra.caselle[0].length; j++) {
				if (finestra.caselle[i][j].isChecked())
					conta[i]++;
			}
		}
		String s = "Numeri vincenti:"
					+ "\nruota 1: " + conta[0]
					+ "\nruota 2: " + conta[1]
					+ "\nruota 3: " + conta[2]
					+ "\nruota 4: " + conta[3]
					+ "\nruota 5: " + conta[4];
											
		JOptionPane.showMessageDialog(finestra, s);
	}

}
