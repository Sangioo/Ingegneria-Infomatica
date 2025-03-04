#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int*, int);
void printArray(int*, int);
void genArray(int*, int);
void launcher(int*, int);

int main(int argc, char *argv[]) {
	int n;
	if (argc == 1) {
		n = 10;
	} else {
		n = argc - 1;
	}

	int arr[n];

	if (argc == 1) {
		genArray(arr, n);
	} else {
		for (int i=1; i<n+1; i++) {
			arr[i-1] = *argv[i] - 48;
		}
	}
	printf("array prima dell'ordinamento:\n");
	printArray(arr, n);

	launcher(arr, n);

	printf("array dopo l'ordinamento:\n");
	printArray(arr, n);

	return 0;
}

void printArray(int* arr, int n) {
	for (int i=0; i<n; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void genArray(int *arr, int n) {
	srand(time(NULL));
	for (int i=0; i<n; i++) arr[i] = rand();
}

void launcher(int *arr, int n) {
	printf("start del bubblesort...\n");
	clock_t start = clock();
	bubbleSort(arr, n);
	clock_t end = clock();
	printf("tempo di esecuzione: %f ms\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC);
}
