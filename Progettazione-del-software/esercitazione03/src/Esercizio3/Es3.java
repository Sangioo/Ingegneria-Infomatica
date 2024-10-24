package Esercizio3;

import java.util.Scanner;
import Esercizio2.Es2;
import Esercizio1.Es1;

public class Es3 {

    public static double[][] inserisciMatrice() {
        Scanner scan = new Scanner(System.in);

        System.out.println("Inserire le dimensioni della matrice (separati da \", \"):");
        String[] riga = scan.nextLine().split(", ");
        int n = Integer.parseInt(riga[0]);
        int m = Integer.parseInt(riga[1]);

        System.out.println("\nInserire i valori della matrice (separati da \", \"):");
        double[][] mat = new double[n][m];
        for (int i=0; i<n; ++i) {
            riga = scan.nextLine().split(", ");

            for (int j=0; j<m; ++j) {
                mat[i][j] = Double.parseDouble(riga[j]);
            }
        }
        scan.close();

        return mat;
    }

    public static void esercizio3() {
        System.out.println("\nESERCIZIO 3: \n");

        double[][] mat = inserisciMatrice();
        System.out.println("\nMatrice inserita:");
        Es1.stampaMatrice(mat);

        System.out.println("\nDifferenza vicini:");
        double[][] vicini = Es2.differenzaVicini(mat);
        Es1.stampaMatrice(vicini);
    }
}
