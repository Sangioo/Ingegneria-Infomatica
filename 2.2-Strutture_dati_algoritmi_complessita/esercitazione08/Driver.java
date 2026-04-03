import java.util.Random;

public class Driver {
    public static void main(String[] args) {

        int[] arrTest = new int[] { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };

        if (args.length != 0 && args[0].equals("brute")) {
            System.out.println("Somma attesa: 187");
            Azzardo.GiocataVincente resultBrute = Azzardo.bruteForce(arrTest);
            if (resultBrute.start == -1) {
                System.out.println("  Nessun intervallo valido (array vuoto).");
            } else {
                System.out.println("  Intervallo massimo: da indice " + resultBrute.start + " a " + resultBrute.end);
                System.out.println("  Sottoarray massimo: " + java.util.Arrays.toString(resultBrute.subPlay));
                System.out.println("  Somma massima: " + resultBrute.maxWin);
            }
        } else if (args.length != 0 && args[0].equals("faster")) {
            System.out.println("Somma attesa: 187");
            Azzardo.GiocataVincente resultFaster = Azzardo.faster(arrTest);
            if (resultFaster.start == -1) {
                System.out.println("  Nessun intervallo valido (array vuoto).");
            } else {
                System.out.println("  Intervallo massimo: da indice " + resultFaster.start + " a " + resultFaster.end);
                System.out.println("  Sottoarray massimo: " + java.util.Arrays.toString(resultFaster.subPlay));
                System.out.println("  Somma massima: " + resultFaster.maxWin);
            }
        } else if (args.length != 0 && args[0].equals("bolt")) {
            System.out.println("Somma attesa: 187");
            Azzardo.GiocataVincente resultBolt = Azzardo.bolt(arrTest);
            if (resultBolt.start == -1) {
                System.out.println("  Nessun intervallo valido (array vuoto).");
            } else {
                System.out.println("  Intervallo massimo: da indice " + resultBolt.start + " a " + resultBolt.end);
                System.out.println("  Sottoarray massimo: " + java.util.Arrays.toString(resultBolt.subPlay));
                System.out.println("  Somma massima: " + resultBolt.maxWin);
            }
        } else if (args.length != 0 && args[0].equals("golden")) {
            System.out.println("Somma attesa: 187");
            Azzardo.GiocataVincente resultGolden = Azzardo.goldenSolution(arrTest);
            if (resultGolden.start == -1) {
                System.out.println("  Nessun intervallo valido (array vuoto).");
            } else {
                System.out.println("  Intervallo massimo: da indice " + resultGolden.start + " a " + resultGolden.end);
                System.out.println("  Sottoarray massimo: " + java.util.Arrays.toString(resultGolden.subPlay));
                System.out.println("  Somma massima: " + resultGolden.maxWin);
            }
        } else {
            System.out.println("------------------------------------------------------------- Somma attesa: 187");
            int[] arr1 = new int[] { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };
            System.out.println("Input: " + java.util.Arrays.toString(arr1));
            test(arr1);

            System.out.println("------------------------------------------------------------- Somma attesa: 8");
            int[] arr2 = new int[] { 1, -2, 3, 5, -3, 2 };
            System.out.println("Input: " + java.util.Arrays.toString(arr2));
            test(arr2);

            System.out.println("------------------------------------------------------------- Somma attesa: -1");
            int[] arr3 = new int[] { -2, -3, -1, -5 };
            System.out.println("Input: " + java.util.Arrays.toString(arr3));
            test(arr3);

            System.out.println("------------------------------------------------------------- Somma attesa: 6");
            int[] arr4 = new int[] { 4, -1, 2, 1 };
            System.out.println("Input: " + java.util.Arrays.toString(arr4));
            test(arr4);

            System.out.println("------------------------------------------------------------- Somma attesa: 5");
            int[] arr5 = new int[] { 5 };
            System.out.println("Input: " + java.util.Arrays.toString(arr5));
            test(arr5);

            int[] array = new int[3200];
            Random rand = new Random();
            for (int i = 0; i < array.length; i++) {
                array[i] = rand.nextInt(201) - 100;
            }

            System.out.println();
            System.out.println("------------------------------------------------------------- *** Prova a tempo ***");
            testTime(array);
        }
    }

    private static void test(int[] array) {
        Azzardo.GiocataVincente resultBrute = Azzardo.bruteForce(array);
        Azzardo.GiocataVincente resultFaster = Azzardo.faster(array);
        Azzardo.GiocataVincente resultBolt = Azzardo.bolt(array);
        Azzardo.GiocataVincente resultGolden = Azzardo.goldenSolution(array);

        System.out.println("******* TEST ALGORITMO BRUTE");
        if (resultBrute.start == -1) {
            System.out.println("  Nessun intervallo valido (array vuoto).");
        } else {
            System.out.println("  Intervallo massimo: da indice " + resultBrute.start + " a " + resultBrute.end);
            System.out.println("  Sottoarray massimo: " + java.util.Arrays.toString(resultBrute.subPlay));
            System.out.println("  Somma massima: " + resultBrute.maxWin);
        }
        System.out.println();

        System.out.println("******* TEST ALGORITMO FASTER");
        if (resultFaster.start == -1) {
            System.out.println("  Nessun intervallo valido (array vuoto).");
        } else {
            System.out.println("  Intervallo massimo: da indice " + resultFaster.start + " a " + resultFaster.end);
            System.out.println("  Sottoarray massimo: " + java.util.Arrays.toString(resultFaster.subPlay));
            System.out.println("  Somma massima: " + resultFaster.maxWin);
        }
        System.out.println();

        System.out.println("******* TEST ALGORITMO BOLT");
        if (resultBolt.start == -1) {
            System.out.println("  Nessun intervallo valido (array vuoto).");
        } else {
            System.out.println("  Intervallo massimo: da indice " + resultBolt.start + " a " + resultBolt.end);
            System.out.println("  Sottoarray massimo: " + java.util.Arrays.toString(resultBolt.subPlay));
            System.out.println("  Somma massima: " + resultBolt.maxWin);
        }
        System.out.println();

        System.out.println("******* TEST ALGORITMO GOLDEN");
        if (resultGolden.start == -1) {
            System.out.println("  Nessun intervallo valido (array vuoto).");
        } else {
            System.out.println("  Intervallo massimo: da indice " + resultGolden.start + " a " + resultGolden.end);
            System.out.println("  Sottoarray massimo: " + java.util.Arrays.toString(resultGolden.subPlay));
            System.out.println("  Somma massima: " + resultGolden.maxWin);
        }
        System.out.println();
    }

    private static void testTime(int[] array) {
        long startBrute = System.currentTimeMillis();
        Azzardo.GiocataVincente resultBrute = Azzardo.bruteForce(array);
        long endBrute = System.currentTimeMillis();
        long executionTimeBrute = endBrute - startBrute;

        long startQuadratic = System.currentTimeMillis();
        Azzardo.GiocataVincente resultQuadratic = Azzardo.faster(array);
        long endQuadratic = System.currentTimeMillis();
        long executionTimeQuadratic = endQuadratic - startQuadratic;

        long startLog = System.currentTimeMillis();
        Azzardo.GiocataVincente resultLog = Azzardo.bolt(array);
        long endLog = System.currentTimeMillis();
        long executionTimeLog = endLog - startLog;

        long startLinear = System.currentTimeMillis();
        Azzardo.GiocataVincente resultLinear = Azzardo.goldenSolution(array);
        long endLinear = System.currentTimeMillis();
        long executionTimeLinear = endLinear - startLinear;

        System.out.println("BRUTE FORCE: " + executionTimeBrute + " ms");
        System.out.println("FASTER: " + executionTimeQuadratic + " ms");
        System.out.println("BOLT: " + executionTimeLog + " ms");
        System.out.println("GOLDEN: " + executionTimeLinear + " ms");
    }
}