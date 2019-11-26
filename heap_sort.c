# include <stdio.h>
# include <stdlib.h>

void heapify(int* a, int n, int i) {
	int temp;
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[left] > a[largest]) {
		largest = left;
	}
	if (right < n && a[right] > a[largest]) {
		largest = right;
	}
	if (largest != i) {
		temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		heapify(a, n, largest);
	}
}

void heapsort(int* a, int n) {
	int temp;
	for (int i = n / 2; i >= 0; i--) {
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		heapify(a, i, 0);
	}
}

void display(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

void main() {
	int n = 7;
	int ar[] = { 7, 4, 6, 2, 3, 5, 1 };
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		a[i] = ar[i];
	heapsort(a, n);
	printf("Sorted : ");
	display(a, n);
}