# include <stdio.h>
# include <stdlib.h>

void display(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

int partitionindex(int* a, int start, int end) {
	int temp;
	int pivot = a[end];
	int partition_index = start;
	for (int i = start; i < end; i++) {
		if (a[i] < pivot) {
			temp = a[i];
			a[i] = a[partition_index];
			a[partition_index] = temp;
			partition_index++;
		}
	}
	temp = a[partition_index];
	a[partition_index] = a[end];
	a[end] = temp;
	return partition_index;
}

void quicksort(int* a, int start, int end) {
	if (start < end) {
		int partition_index = partitionindex(a, start, end);
		quicksort(a, start, partition_index - 1);
		quicksort(a, partition_index + 1, end);
	}
}

void main() {
	int n = 7;
	int ar[] = { 7, 4, 6, 2, 3, 5, 1 };
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		a[i] = ar[i];
	quicksort(a, 0, n);
	printf("Sorted : ");
	display(a, n);
}