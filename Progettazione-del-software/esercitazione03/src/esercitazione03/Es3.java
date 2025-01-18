package esercitazione03;

import java.util.Scanner;

public class Es3 {
	public static double[][] processaInput() {
		Scanner scan = new Scanner(System.in);
		String[] riga = scan.nextLine().split(",");
		int n = Integer.parseInt(riga[0]);
		int m = Integer.parseInt(riga[1]);
		
		double[][] out = new double[n][m];
		for (int i=0; i<n; i++) {
			riga = scan.nextLine().split(",");
			for (int j=0; j<m; j++) {
				out[i][j] = Integer.parseInt(riga[j]);
			}
		}
		
		scan.close();
		return out;
	}
	
	public static void esercizio3()	{
		System.out.println("##ESERCIZIO 3##");
		
		System.out.println("Inserire input:");
		double[][] mat = Es3.processaInput();
		
		System.out.println("\nMatrice inserita");
		Es1.stampaMatrice(mat);
		
		System.out.println("\nMatrice differenza vicini:");
		double[][] out = Es2.differenzaVicini(mat);
		Es1.stampaMatrice(out);
	}
}
