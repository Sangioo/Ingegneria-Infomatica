package esercitazione03;

public class Es2 {
	public static double[][] differenzaVicini(double[][] mat) {
		int n = mat.length;
		int m = mat[0].length;
		double[][] out = new double[n][m];
		
		for (int i=0; i<mat.length; i++) {
			for (int j=0; j<mat[0].length; j++) {
				int somma = 0;
				somma += isValid(i-1, j-1, n, m) ? mat[i-1][j-1] : 0;
				somma += isValid(i-1, j, n, m)   ? mat[i-1][j]   : 0;
				somma += isValid(i-1, j+1, n, m) ? mat[i-1][j+1] : 0;
				
				somma += isValid(i, j-1, n, m)   ? mat[i][j-1]   : 0;
				somma += isValid(i, j+1, n, m)   ? mat[i][j+1]   : 0;
				
				somma += isValid(i+1, j-1, n, m) ? mat[i+1][j-1] : 0;
				somma += isValid(i+1, j, n, m)   ? mat[i+1][j]   : 0;
				somma += isValid(i+1, j+1, n, m) ? mat[i+1][j+1] : 0;
				
				out[i][j] = mat[i][j] - somma;
			}
		}
		
		return out;
	}
	
	private static boolean isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}
	
	public static void esercizio2() {
		System.out.println("##ESERCIZIO 2##");
		
		double[][] mat = Es1.generaMatrice(5, 5);
		System.out.println("Matrice:");
		Es1.stampaMatrice(mat);
		
		System.out.println("\nMatrice differenza vicini:");
		double[][] out = Es2.differenzaVicini(mat);
		Es1.stampaMatrice(out);
	}
}
