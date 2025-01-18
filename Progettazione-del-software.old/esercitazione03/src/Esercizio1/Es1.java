package Esercizio1;
import java.util.Scanner;

public class Es1 {

    public static double[][] generaMatrice(int n, int m) {
        double[][] mat = new double[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                mat[i][j] = Math.random() * 100;
            }
        }
        return mat;
    }

    public static void stampaMatrice(double[][] mat) {
        for (double[] riga : mat) {
            for (double elem : riga) {
                System.out.print(Double.toString(elem) + "\t");
            }
            System.out.println();
        }
    }

    public static void stampaArray(double[] arr) {
        for (double elem : arr) {
            System.out.print(Double.toString(elem) + "\t");
        }
        System.out.println();
    }

    public static double[] diagonale(double[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int max;
        if (n > m) {
            max = m;
        } else {
            max = n;
        }

        double[] diag = new double[max];
        for (int i=0; i<max; i++) {
            diag[i] = mat[i][i];
        }

        return diag;
    }

    public static double sommaArray(double[] arr) {
        double somma = 0;
        for (double elem : arr) {
            somma += elem;
        }
        return somma;
    }

    public static void esercizio1() {
        Scanner scan = new Scanner(System.in);

        System.out.println("\nESERCIZIO 1:\n");
        System.out.print("Inserire n: ");
        int n = Integer.parseInt(scan.nextLine());
        System.out.print("Inserire m: ");
        int m = Integer.parseInt(scan.nextLine());
        scan.close();

        double[][] mat = generaMatrice(n, m);
        System.out.println("\nMatrice generata:");
        stampaMatrice(mat);

        double[] diag = diagonale(mat);
        System.out.println("\nDiagonale:");
        stampaArray(diag);
        System.out.println("\nSomma elementi diagonale: " + String.valueOf(sommaArray(diag)));
    }
}
