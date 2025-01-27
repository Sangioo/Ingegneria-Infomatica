import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

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
		case "Stop":
			stop();
			break;
		case "Image 1":
		case "Image 2":
		case "Image 3":
		case "Image 4":
		case "Image 5":
			start(e.getActionCommand().charAt(6));
			break;
		default:
			System.out.println("Comando non riconosciuto");
		}
	}

	private void connect(String address, String porta) {
		try {
			sock = new Socket(address, Integer.parseInt(porta));
			input = new Scanner(sock.getInputStream());
			output = new PrintWriter(sock.getOutputStream());
			finestra.setPulsanti(true, false);
			finestra.resetArea();
		} catch (IOException e) {
			System.out.println("Errore di connessione");
		} catch (NumberFormatException e) {
			System.out.println("Numero di porta non valido");
		}
	}

	private void disconnect() {
		try {
			input.close();
			output.close();
			sock.close();
			finestra.setPulsanti(false, false);
		} catch (IOException e) {
			System.out.println("Errore di disconnessione");
		}
	}

	private void stop() {
		output.println("stop");
		output.flush();
		finestra.setPulsanti(true, false);
	}

	private void start(char num) {
		finestra.setPulsanti(true, true);
		finestra.appendArea("========================== Download iniziato ==========================");
		output.println("start:image" + num);
		output.flush();
		
		Thread t = new Thread(new Downloader(finestra, input));
		t.start();
	}

}
