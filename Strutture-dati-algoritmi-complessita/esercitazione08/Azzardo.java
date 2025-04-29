import java.util.ArrayList;
import java.util.Arrays;

public class Azzardo {

    public static class GiocataVincente {
        int start; // Indice di partenza della giocata vincente
        int end; // Indice di fine della giocata vincente
        int maxWin; // Vincita massima della giocata vincente
        int[] subPlay; // Sequenza della giocata vincente

        public GiocataVincente(int start, int end, int maxWin, int[] subPlay) {
            this.start = start;
            this.end = end;
            this.maxWin = maxWin;
            this.subPlay = subPlay;
        }
    }

    public static GiocataVincente bruteForce(int[] listaPartite) {
        int maxI = 0, maxJ = 0, maxWin, sum;

        maxWin = listaPartite[0];
        for (int i = 0; i < listaPartite.length; i++) {
            for (int j = i; j < listaPartite.length; j++) {
                sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += listaPartite[k];
                }
                if (sum >= maxWin) {
                    maxI = i;
                    maxJ = j;
                    maxWin = sum;
                }
            }
        }
        int[] out = new int[maxJ - maxI + 1];
        for (int i = 0; i < out.length; i++)
            out[i] = listaPartite[i + maxI];

        return new GiocataVincente(maxI, maxJ, maxWin, out);
    }

    public static GiocataVincente faster(int[] listaPartite) {
        int maxI = 0, maxJ = 0, maxWin, sum;

        maxWin = listaPartite[0];
        for (int i = 0; i < listaPartite.length - 1; i++) {
            sum = 0;
            for (int j = i; j < listaPartite.length; j++) {
                sum += listaPartite[j];
                if (sum >= maxWin) {
                    maxI = i;
                    maxJ = j;
                    maxWin = sum;
                }
            }
        }

        int[] out = new int[maxJ - maxI + 1];
        for (int i = 0; i < out.length; i++)
            out[i] = listaPartite[i + maxI];

        return new GiocataVincente(maxI, maxJ, maxWin, out);
    }

    public static GiocataVincente bolt(int[] listaPartite) {
        int[] out = bolt_aux(listaPartite, 0, listaPartite.length - 1);
        int[] interval = new int[out[1] - out[0] + 1];

        for (int i = 0; i < interval.length; i++) {
            interval[i] = listaPartite[i + out[0]];
        }

        return new GiocataVincente(out[0], out[1], out[2], interval);
    }

    private static int[] bolt_aux(int[] arr, int start, int end) {
        if (start == end) {
            int[] ret = { start, end, arr[start] };
            return ret;
        } else {
            int mid = (int) Math.floor((start + end) / 2);
            int[] left = bolt_aux(arr, start, mid);
            int[] right = bolt_aux(arr, mid + 1, end);
            int[] cross = bolt_cross_aux(arr, start, mid, end);

            if (left[2] >= right[2] && left[2] >= cross[2]) {
                return left;
            } else if (right[2] >= left[2] && right[2] >= cross[2]) {
                return right;
            } else {
                return cross;
            }
        }
    }

    private static int[] bolt_cross_aux(int[] arr, int start, int mid, int end) {
        int maxLeft = mid;
        int left = arr[mid];
        int sum = 0;
        for (int i = mid; i >= start; i--) {
            sum += arr[i];
            if (sum >= left) {
                left = sum;
                maxLeft = i;
            }
        }

        int maxRight = mid + 1;
        int right = arr[mid + 1];
        sum = 0;
        for (int i = mid + 1; i <= end; i++) {
            sum += arr[i];
            if (sum >= right) {
                right = sum;
                maxRight = i;
            }
        }

        int[] ret = { maxLeft, maxRight, left + right };
        return ret;
    }

    public static GiocataVincente goldenSolution(int[] listaPartite) {
        int best = listaPartite[0];
        int current = listaPartite[0];
        int maxI = 0, maxJ = 0, currI = 0;

        for (int i = 1; i < listaPartite.length; i++) {
            if (listaPartite[i] >= current + listaPartite[i]) {
                currI = i;
                current = listaPartite[i];
            } else {
                current += listaPartite[i];
            }

            if (current >= best) {
                maxI = currI;
                maxJ = i;
                best = current;
            }
        }

        int[] interval = new int[maxJ - maxI + 1];
        for (int i = 0; i < interval.length; i++) {
            interval[i] = listaPartite[i + maxI];
        }

        return new GiocataVincente(maxI, maxJ, best, interval);
    }
}
