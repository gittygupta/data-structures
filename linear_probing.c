
# include <stdio.h>
# define MAX 11

void hash(int a[], int element) {
	int remainder = element % MAX;
	int i = remainder;
	if (a[remainder] == -1) {
		a[remainder] = element;
	}
	else {
		i += 1;
		while (i != remainder) {
			if (a[i] == -1) {
				a[i] = element;
				return;
			}
			i++;
			if (i == MAX) {
				i = 0;
			}
		}
	}
}

void main() {
	int a[MAX];
	for (int i = 0; i < MAX; i++)
		a[i] = -1;
	int x;
	for (int i = 0; i < MAX; i++) {
		printf("Enter element:");
		scanf("%d", &x);
		hash(a, x);
	}
	printf("Hash table:\n");
	for (int i = 0; i < MAX; i++)
		printf("%d ", a[i]);
}
