#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define exch(x, y) { int tmp = x; x = y; y = tmp; }
#define N 20

void reverse(int a[], int n)
{
	int i, j;

	for (i = 0, j = n - 1; i < j; i++, j--)
		exch(a[i], a[j]);
}

int main(void)
{
	int i, a[N];

	srand((unsigned int) time(0));
	for (i = 0; i < N; i++) {
		a[i] = rand() % N + 1; 
		printf(" %d", a[i]);
	}
	printf("\n");
	reverse(a, N);
	for (i = 0; i < N; i++)
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}
