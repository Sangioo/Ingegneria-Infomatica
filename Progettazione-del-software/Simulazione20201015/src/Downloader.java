import java.util.Scanner;

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
			
			if (riga.equals("END")) {
				finestra.appendArea("========================= Download completato =========================");
				break;
			} else if (riga.equals("INTERRUPTED")) {
				finestra.appendArea("========================= Download interrotto =========================");
				break;
			} else if (riga.equals("ERROR")) {
				finestra.appendArea("=============================== Errore ================================");
				break;
			} else {
				finestra.appendArea(riga);
			}
		}
		finestra.setPulsanti(true, false);
	}

}
