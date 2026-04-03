import java.util.ArrayList;

public class Heap {

    public enum HEAP_TYPE {
        MAX_HEAP, MIN_HEAP
    };

    private HEAP_TYPE type;
    private int[] array;
    private HeapEntry[] heap;
    private int heapCapacity;
    private int heapSize;

    static class HeapEntry {
        private int key;
        private int position; // Indice della posizione dell'array in cui si trova l'elemento

        HeapEntry(int key, int position) {
            this.key = key;
            this.position = position;
        }
    }

    public Heap(HEAP_TYPE type, int capacity) {
        this.type = type;
        this.array = new int[capacity];
        this.heapCapacity = (int) Math.pow(2, Math.ceil(Math.log(capacity) / Math.log(2)));
        this.heap = new HeapEntry[heapCapacity];
        this.heapSize = 0;
    }

    private int parent(int i) {
        return (i - 1) / 2;
    }

    private void swap(int i, int j) {
        int tmp = heap[j].key;
        heap[j].key = heap[i].key;
        heap[i].key = tmp;
    }

    private void swap_sync(int i, int j) {
        int tmp = heap[j].key;
        heap[j].key = heap[i].key;
        heap[i].key = tmp;
    }

    private boolean compare(int k1, int k2) {
        if (this.getType() == HEAP_TYPE.MAX_HEAP) {
            return k1 < k2;
        } else {
            return k1 > k2;
        }
    }

    public HEAP_TYPE getType() {
        return this.type;
    }

    public int peek() {
        return heap[0].key;
    }

    public HeapEntry add(int key) {
        HeapEntry new_key = new HeapEntry(key, this.heapSize);
        this.heap[new_key.position] = new_key;
        this.heapSize++;

        int i = this.heapSize - 1;
        while (i > 0 && compare(heap[parent(i)].key, heap[i].key)) {
            swap(i, parent(i));
            i = parent(i);
        }

        return heap[i];
    }

    public int getEntryKey(HeapEntry e) {
        return e.key;
    }

    public int size() {
        return this.heapSize;
    }

    public int poll() {
        int max = this.peek();
        heap[0] = heap[heapSize - 1];
        this.heapSize--;

        if (this.getType() == HEAP_TYPE.MAX_HEAP) {
            this.max_heapify(0);
        } else {
            this.min_heapify(0);
        }
        return max;
    }

    public static Heap array2heap(int[] array, HEAP_TYPE type) {
        Heap heap = new Heap(type, array.length);
        heap.heapSize = array.length;

        for (int i = 0; i < heap.heapSize; i++) {
            HeapEntry e = new HeapEntry(array[i], i);
            heap.heap[i] = e;
            heap.array[i] = array[i];
        }

        for (int i = heap.heapSize / 2; i >= 0; i--) {
            if (type == HEAP_TYPE.MAX_HEAP) {
                heap.max_heapify(i);
            } else {
                heap.min_heapify(i);
            }
        }
        return heap;
    }

    public void print() {
        for (int i = 0; i < heapSize; i++) {
            System.out.print(" ");
            System.out.print(heap[i].key);
        }
        System.out.println(" ");
    }

    public static void heapSort(int[] array) {
        Heap heap = array2heap(array, HEAP_TYPE.MAX_HEAP);
        for (int i = heap.size() - 1; i >= 0; i--) {
            heap.swap(0, i);
            heap.heapSize--;
            array[i] = heap.heap[i].key;
            heap.max_heapify(0);
        }
    }

    public void updateEntryKey(HeapEntry e, int key) {
        this.heap[e.position].key = key;

        if (type == HEAP_TYPE.MAX_HEAP) {
            this.max_heapify(e.position);
        } else {
            this.min_heapify(e.position);
        }
    }

    private void max_heapify(int i) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int max = i;
        if (l < this.heapSize && heap[l].key > heap[i].key) {
            max = l;
        } else {
            max = i;
        }
        if (r < this.heapSize && heap[r].key > heap[max].key) {
            max = r;
        }
        if (max != i) {
            swap(i, max);
            this.max_heapify(max);
        }
    }

    private void min_heapify(int i) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int min = i;
        if (l < this.heapSize && heap[l].key < heap[i].key) {
            min = l;
        } else {
            min = i;
        }
        if (r < this.heapSize && heap[r].key < heap[min].key) {
            min = r;
        }
        if (min != i) {
            swap(i, min);
            this.min_heapify(min);
        }
    }
}
