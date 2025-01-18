package Esercizio2;

import Esercizio1.Es1;

public class Es2 {

    public static boolean isValid(int i, int j, int rows, int cols) {
        return (0 <= i && i < rows && 0 <= j && j < cols);
    }

    public static double[][] differenzaVicini(double[][] in) {
        int rows = in.length;
        int cols = in[0].length;
        double[][] out = new double[rows][cols];
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                out[i][j] = in[i][j];

                if(isValid(i-1, j-1, rows, cols)) out[i][j] -= in[i-1][j-1];
                if(isValid(i-1, j, rows, cols)) out[i][j] -= in[i-1][j];
                if(isValid(i-1, j+1, rows, cols)) out[i][j] -= in[i-1][j+1];

                if(isValid(i, j-1, rows, cols)) out[i][j] -= in[i][j-1];
                if(isValid(i, j+1, rows, cols)) out[i][j] -= in[i][j+1];

                if(isValid(i+1, j-1, rows, cols)) out[i][j] -= in[i+1][j-1];
                if(isValid(i+1, j, rows, cols)) out[i][j] -= in[i+1][j];
                if(isValid(i+1, j+1, rows, cols)) out[i][j] -= in[i+1][j+1];

            }
        }
        return out;
    }

    public static void esercizio2() {
        System.out.println("\nESERCIZIO 2:\n");
        double[][] mat = Es1.generaMatrice(5, 5);
        double[][] vicini = differenzaVicini(mat);
        Es1.stampaMatrice(vicini);
    }
}
