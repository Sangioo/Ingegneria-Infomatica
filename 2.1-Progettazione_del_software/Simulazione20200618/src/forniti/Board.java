/*
 * Board.java
 *
 * NOTE: Inserire qui la direttiva package se la classe viene spostata
 * in un package che non è quello di default.
 */
package forniti;

import javax.swing.JOptionPane;
import javax.swing.JPanel;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Iterator;

/**
 * <p>
 * La classe {@code Board} realizza il pannello centrale dell'interfaccia
 * grafica del client, che rappresenta il tabellone di gioco del campo minato.
 *
 * Lo studente può, a sua discrezione, completare il codice seguendo i
 * suggerimenti inseriti ed utilizzare questa classe, oppure può fornire una sua
 * implementazione, ignorando completamente questa classe se lo ritiene
 * appropriato.
 *
 * Qualora non venga utilizzata, questa classe può comunque essere consegnata
 * insieme al resto del codice, a patto che le eventuali modifiche apportate non
 * comportino errori di compilazione.
 * </p>
 */
public class Board extends JPanel implements ActionListener {
	/*
	 * Inserire qui una struttura dati per la memorizzazione delle istanze di {@code
	 * BoardButton}. Si suggerisce di utilizzare una matrice, ma è possibile
	 * utilizzare qualsiasi altra struttura dati se lo si ritiene appropriato (lista
	 * di liste, array {row,column}-major, ecc).
	 */
	private final static int LATO = 10;
	private BoardButton[][] caselle = new BoardButton[LATO][LATO];

	/*
	 * Inserire qui il costruttore della classe
	 */
	public Board() {
		super();
		this.setLayout(new GridLayout(LATO, LATO));
		for (int i = 0; i < LATO; i++) {
			for (int j = 0; j < LATO; j++) {
				caselle[i][j] = new BoardButton();
				caselle[i][j].setEnabled(false);
				caselle[i][j].addActionListener(this);
				this.add(caselle[i][j]);
			}
		}
	}

	/**
	 * Restituisce l'istanza di {@code BoardButton} all'indice ({@code row},
	 * {@code column}).
	 * 
	 * @param row    l'indice di riga del pulsante
	 * @param column l'indice di colonna del pulsante
	 * @return l'istanza di {@code BoardButton} per l'indice ({@code row},
	 *         {@code column}).
	 */
	public BoardButton getButton(int row, int column) {
		return caselle[row][column];
	}

	/**
	 * Il compito di questo metodo è quello di attivare o disattivare l'interazione
	 * con le caselle del gioco, utilizzando il metodo {@code setEnabled(boolean)}
	 * sulle istanze di {@code BoardButton}. Se il parametro {@code active} è
	 * {@code true}, allora il gioco viene attivato (i.e. i pulsanti possono essere
	 * premuti), altrimenti viene disattivato (i.e. i pulsanti non possono essere
	 * premuti).
	 */
	public void setGameActive(boolean active) {
		for (int i = 0; i < caselle.length; i++) {
			for (int j = 0; j < caselle[0].length; j++) {
				caselle[i][j].setEnabled(active);
			}
		}
	}

	/**
	 * Reset del gioco allo stato iniziale, chiamando il metodo {@code reset()} per
	 * tutte le istanze di {@code BoardButton}.
	 */
	public void resetGame() {
		for (int i = 0; i < caselle.length; i++) {
			for (int j = 0; j < caselle[0].length; j++) {
				caselle[i][j].reset();
			}
		}
	}

	/**
	 * Rivela il contenuto di tutte le caselle del gioco (i.e. chiama
	 * {@code reveal()} su tutte le istanze di {@code BoardButton}.
	 */
	public void revealBoard() {
		for (int i = 0; i < caselle.length; i++) {
			for (int j = 0; j < caselle[0].length; j++) {
				caselle[i][j].reveal();
			}
		}
	}

	/**
	 * La classe {@code Board} aggisce da <i>listener</i> per le istanze di
	 * {@code BoardButton}. N.B. come sempre per fare ciò è necessario aggiungerla
	 * alla lista dei listener per ogni istanza di {@code BoardButton}.
	 *
	 * Suggerimento: è possibile ottenere un riferimento al componente che ha
	 * scatenato l'evento attraverso la chiamata a {@code e.getSource()}.
	 *
	 * @param e l'evento scatenante la chiamata
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		BoardButton bottone = (BoardButton) e.getSource();
		bottone.reveal();
		
		if (bottone.hasMine()) {
			this.setGameActive(false);
			JOptionPane.showMessageDialog(bottone, "Mi dispiace, hai perso :(");
			return;
		}
		
		for (int i = 0; i < caselle.length; i++) {
			for (int j = 0; j < caselle[0].length; j++) {
				if (!caselle[i][j].hasMine() && caselle[i][j].isEnabled()) {
					return;
				}
			}
		}
		this.setGameActive(false);
		JOptionPane.showMessageDialog(this, "Congratulazioni, hai vinto!");
	}

}
