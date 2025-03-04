void bubbleSort(int*, int);

void bubbleSort(int* arr, int n) {
	if (n <= 1) return;

	for (int i=0; i<n-1; i++) {
		for (int j=0; j<n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return;
}