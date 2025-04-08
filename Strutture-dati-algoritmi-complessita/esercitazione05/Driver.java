/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author silvia
 */
public class Driver {
    
    public static void stampaArray(float [] a){
        System.out.print("[");
        for (int i=0; i<a.length-1; i++){
            System.out.print(a[i] + ", ");
        }
        System.out.println(a[a.length-1] + "]");
    }
    
    public static void stampaArray(char [] a){
        System.out.print("[");
        for (int i=0; i<a.length-1; i++){
            System.out.print(a[i] + ", ");
        }
        System.out.println(a[a.length-1] + "]");
    }
    
    public static void stampaMatrice(int [][] m){
        for (int i=0; i<m.length; i++){
            for(int j=0; j<m[0].length; j++){
                System.out.print(m[i][j]+"\t");
            }
            System.out.println();
        }
    }
    
    public static void main(String [] args){
        float[] a1={1, -2, 3, -1, -4, -3};
        float[] a2={0, -2, 3, 1, -4, -3};
        float[] a3={0, 2, 3, 1, -4, -3, -125};
        System.out.println("TEST 1: il vettore di input è:");
        Driver.stampaArray(a1);
        Algoritmi.permuta_negativi_positivi(a1);
        System.out.println("TEST 1: il vettore di output generato dalla tua soluzione è:");
        Driver.stampaArray(a1);
        System.out.println("TEST 1: il vettore di output generato dalla soluzione del Docente è: ");
        Soluzione.permuta_negativi_positivi(a1);
        Driver.stampaArray(a1);
       
        System.out.println();
        
        System.out.println("TEST 2: il vettore di input è:");
        Driver.stampaArray(a2);
        Algoritmi.permuta_negativi_positivi(a2);
        System.out.println("TEST 2: il vettore di output generato dalla tua soluzione è:");
        Driver.stampaArray(a2);
         System.out.println("TEST 2: il vettore di output generato dalla soluzione del Docente è: ");
        Soluzione.permuta_negativi_positivi(a2);
        Driver.stampaArray(a2);
        
        System.out.println();
        
        char [] b1={'r', 'v', 'r', 'v', 'b', 'v', 'r'};
        System.out.println("TEST 3: il vettore di input è:");
        Driver.stampaArray(b1);
        Algoritmi.bandiera(b1);
        System.out.println("TEST 3: il vettore di output generato dalla tua soluzione è:");
        Driver.stampaArray(b1);
        System.out.println("TEST 3: il vettore di output generato dalla soluzione del Docente è: ");
        Soluzione.bandiera(b1);
        Driver.stampaArray(b1);
        
        System.out.println();
        
        int[][] m={{1, 2, 3, 4}, {2, 1, 4, 3}, {4, 3, 2, 1}, {3, 4, 1, 2}};
        System.out.println("TEST 4: la matrice di input è:");
        Driver.stampaMatrice(m);
        boolean res=Algoritmi.isQuadratoLatino(m);
        System.out.println("TEST 4: l'output generato dalla tua soluzione è: "+res);
        res=Soluzione.isQuadratoLatino(m);
        System.out.println("TEST 4: l'output generato dalla soluzione del Docente è: "+res);
       
        System.out.println();
        
        System.out.println("TEST 5: il vettore di input è:");
        Driver.stampaArray(a3);
        Algoritmi.primiKMin(a3, 6);
        System.out.println("TEST 5: la soluzione del Docente è: ");
        Soluzione.primiKMin(a3, 6);
        
    }
    
}
