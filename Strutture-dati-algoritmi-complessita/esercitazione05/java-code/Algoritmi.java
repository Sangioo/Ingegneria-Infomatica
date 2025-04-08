/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.*;
/**
 *
 * @author silvia
 */
public class Algoritmi {
    
     
    public static void permuta_negativi_positivi(float [] a){
		int j = -1;
		for (int i=0; i<a.length; i++) {
			if (a[i] < 0) {
				j++;
				float tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
        return;
	}
    
    public static void bandiera(char[] a){
		bandiera_aux(a, 'b');
		bandiera_aux(a, 'v');
        return;
    }
    
    private static void bandiera_aux(char[] a, char c) {
		int j = -1;
		for (int i=0; i<a.length; i++) {
			if (a[i] == c) {
				j++;
				char tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
       
    public static boolean isQuadratoLatino(int[][] m){
		int lato = m.length;
		int[] colonna = new int[lato];
		int[] riga = new int[lato];
		
		for (int i=0; i<lato; i++) {
			for (int j=0; j<lato; j++) {
				if (riga[m[i][j]-1] > i) return false;
				riga[m[i][j]-1]++;
				
				if (colonna[m[j][i]-1] > i) return false;
				colonna[m[j][i]-1]++;
			}
		}
        return true;
    }
    
        
    public static void primiKMin(float[] a, int k){
		System.out.print("risultato: ");
		
        for (int i=0; i<k; i++) {
			for (int j=i+1; j<a.length; j++) {
				if (a[j] < a[i]) {
					float tmp = a[j];
					a[j] = a[i];
					a[i] = tmp;
				}
			}
			System.out.print(Float.toString(a[i]) + "\t");
		}
		
		System.out.println();
        return;
    }
    
}
