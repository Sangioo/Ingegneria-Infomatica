package forniti;

import javax.swing.JOptionPane;

public class NumberInput implements Reader {

	@Override
	public String read() {
		while (true) {
			try {
				String digit = JOptionPane.showInputDialog("Inserire un numero da 0 a 9 (inclusi)");
				if (digit == null) return "";
				
				int num = Integer.parseInt(digit);
				if (num < 0 || num > 9) throw new Exception();
				
				return digit;
			} catch (Exception e) {
				JOptionPane.showMessageDialog(null, "Numero non valido");
			}
		}
	}

}
