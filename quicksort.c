#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define exch(x, y) { int tmp = x; x = y; y = tmp; }
#define N 20

int partition(int a[], int l, int r)
{
	int i, j;

	i = l - 1;
	j = r;
	for (;;) {
		while (a[++i] < a[r])
			;
		while (a[--j] > a[r])
			if (j == i)
				break;
		if (j <= i)
			break;
		exch(a[i], a[j]);
	}
	exch(a[i], a[r]);
	return i;
}

void quicksort(int a[], int l, int r)
{
	if (l < r) {
		int mid = partition(a, l, r);
		quicksort(a, l, mid - 1);
		quicksort(a, mid + 1, r);
	}
}

int main(void)
{
	srand((unsigned int) time(0));
	int i, a[N];

	for (i = 0; i < N; i++) {
		a[i] = rand() % N + 1;
		printf(" %d", a[i]);
	}
	printf("\nQuicksort:\n");
	quicksort(a, 0, N - 1);
	for (i = 0; i < N; i++)
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}
