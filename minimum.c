#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int minimum(int a[], int n)
{
	int i, min;

	for (min = 0, i = 1; i < n; i++)
		if (a[i] < a[min])
			min = i;
	return min;
}

int main(void)
{
	int i, a[N];

	srand((unsigned int) time(0));
	for (i = 0; i < N; i++) {
		a[i] = rand() % N + 1;
		printf(" %d", a[i]);
	}
	printf("\nminimum: %d\n", minimum(a, N));
	return 0;
}
