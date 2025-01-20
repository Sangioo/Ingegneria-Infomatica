package esercitazione05;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyListener implements ActionListener {
	private MyFrame finestra;
	
	public MyListener(MyFrame frame) {
		this.finestra = frame;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		switch(e.getActionCommand()) {
			case "Connect":
				System.out.println("connect " + finestra.getAddress() + ":" + finestra.getPorta());
				finestra.setPulsanti(true, false);
				break;
			
			case "Start":
				System.out.println("start");
				finestra.setPulsanti(true, true);
				break;
				
			case "Stop":
				System.out.println("stop");
				finestra.setPulsanti(true, false);
				break;
			
			case "Disconnect":
				System.out.println("disconnect");
				finestra.setPulsanti(false, false);
				break;
			
			default:
				System.out.println("AZIONE NON RICONOSCIUTA!");
		}
	}
}
