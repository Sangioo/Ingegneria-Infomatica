package esercitazione03;

import java.util.Scanner;

public class Es1 {
public static double[][] generaMatrice(int n, int m){
		double[][] out = new double[n][m];
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				out[i][j] = Math.random()*100;
			}
		}
		return out;
	}
	
	public static void stampaMatrice(double[][] mat) {
		for (double[] row : mat) {
			stampaArray(row);
		}
	}
	
	public static void stampaArray(double[] arr) {
		for (double elem : arr) {
			System.out.print(elem + "\t");
		}
		System.out.println();
	}
	
	public static double[] diagonale(double[][] mat) {
		int size = mat.length > mat[0].length ? mat[0].length : mat.length;
		
		double[] out = new double[size];
		for (int i=0; i<size; i++) {
			out[i] = mat[i][i];
		}
		return out;
	}
	
	public static double sommaArray(double[] arr) {
		int somma = 0;
		
		for (double elem : arr) {
			somma += elem;
		}
		return somma;
	}
	
	public static void esercizio1() {
		System.out.println("##ESERCIZIO 1##");
		Scanner scan = new Scanner(System.in);
		
		System.out.print("Inserire n: ");
        int n = Integer.parseInt(scan.nextLine());
        System.out.print("Inserire m: ");
        int m = Integer.parseInt(scan.nextLine());
		
		scan.close();
		
		double[][] mat = generaMatrice(n, m);
		double[] diag = diagonale(mat);
		
		System.out.println("\nMatrice:");
		stampaMatrice(mat);
		
		System.out.println("\nDiagonale:");
		stampaArray(diag);
		
		System.out.println("\nSomma diagonale: " + sommaArray(diag));
	}
}
