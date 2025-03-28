import java.util.*;

public class Sort {

    /* Disponibile in libreria java */
    public void quickSortDefault(int[] array) {
        Arrays.sort(array);
    }

    public void mergeSort(int[] array) {
        merge_sort(array, 0, array.length - 1);
        return;
    }

    private void merge_sort(int[] array, int start, int end) {
        if (start >= end) return;

        int medium = (int) Math.floor((start + end) / 2);
        merge_sort(array, start, medium);
        merge_sort(array, medium + 1, end);
        merge(array, start, medium, end);
    }

    private void merge(int[] array, int start, int medium, int end) {
        ArrayList<Integer> temp = new ArrayList<Integer>();
        int left = start;
        int right = medium + 1;

        while (left <= medium && right <= end) {
            if (array[left] < array[right]) {
                temp.addLast(array[left]);
                left++;
            } else {
                temp.addLast(array[right]);
                right++;
            }
        }
        while (left <= medium) {
            temp.addLast(array[left]);
            left++;
        }
        while (right <= end) {
            temp.addLast(array[right]);
            right++;
        }
        for (int i = start; i <= end; i++) {
            array[i] = temp.removeFirst();
        }
    }

    public void heapSort(int[] array) {
        System.out.println("heapSort non è ancora implementato");
        return;
    }

    public void insertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
        return;
    }

    public void selectionSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = i + 1; j < array.length; j++) {
                if (array[i] > array[j]) {
                    int tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                }
            }
        }
        return;
    }

    public void quickSort(int[] array) {
        quick_sort(array, 0, array.length-1);
        return;
    }

    private void quick_sort(int[] array, int start, int end) {
        if (start < end) {
            int pivot = partiziona(array, start, end);
            quick_sort(array, start, pivot-1);
            quick_sort(array, pivot+1, end);
        }
    }

    private int partiziona(int[] array, int start, int end) {
        int x = array[end];
        int k = start-1;
        for (int i=start; i<end; i++) {
            if (array[i] < x) {
                k++;
                int tmp = array[i];
                array[i] = array[k];
                array[k] = tmp;
            }
        }
        k++;
        int tmp = array[k];
        array[k] = array[end];
        array[end] = tmp;
        return k;
    }

    public void radixSort(int[] array) {
        int max = getMax(array);

        for (int e = 1; max/e > 0; e *= 10) {
        }

        return;
    }

    private int getMax(int[] array) {
        int max = array[0];
        for (int i=1; i<array.length; i++) {
            if (array[i] > max)
                max = array[i];
        }
        return max;
    }

    public void bucketSort(int[] array) {
        System.out.println("bucketSort non è ancora implementato");
        return;
    }
}
