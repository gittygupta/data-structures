# include <stdio.h>
# include <stdlib.h>

# define MAX 100
int n = 0;
void insert(int* a, int pos, int item) {
	int i;
	for (i = n; i > pos; i--) {
		a[i] = a[i - 1];
	}
	a[i] = item;
	n++;
}

void delete(int* a, int pos) {
	for (int i = pos; i < MAX; i++) {
		a[i - 1] = a[i];
	}
	n--;
}

void display(int* a) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

void main() {
	n = 7;
	int ar[] = { 1, 2, 3, 4, 5, 6, 7 };
	int* a = (int*)malloc(MAX * sizeof(int));
	for (int i = 0; i < n; i++)
		a[i] = ar[i];
	delete(a, 6 + 1);
	insert(a, 0, 19);
	insert(a, 3, 22);
	display(a);
}