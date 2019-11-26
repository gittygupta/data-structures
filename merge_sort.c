# include <stdio.h>
# include <stdlib.h>

void merge(int* a, int l, int m, int r) {
	int nl = m - l + 1;
	int nr = r - m;
	int left[nl], right[nr];
	int i, j, k;
	for (i = 0; i < nl; i++) {
		left[i] = a[l + i];
	}
	for (j = 0; j < nr; j++) {
		right[j] = a[m + 1 + j];
	}
	i = j = 0;
	k = l;
	while (i < nl && j < nr) {
		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
			k++;
		}
		else {
			a[k] = right[j];
			j++;
			k++;
		}
	}
	while (i < nl) {
		a[k] = left[i];
		i++;
		k++;
	}
	while (j < nr) {
		a[k] = right[j];
		j++;
		k++;
	}
}

void mergesort(int* a, int l, int r) {
	if (l < r) {
		int m = (l + r - 1) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void main() {
	int n = 7;
	int ar[] = { 7, 4, 6, 2, 3, 5, 1 };
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		a[i] = ar[i];
	mergesort(a, 0, n-1);
	printf("Sorted : ");
	display(a, n);
}