#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 20

void delrepeat(int a[], int item)
{
	int i, j, b[N];

	for (i = 0, j = 0; i < N; i++)
		if (a[i] != item)
			b[j++] = a[i];
	memset(a, 0, N * sizeof(int));
	for (i = 0; i < j; i++)
		a[i] = b[i];
}

int main(void)
{
	int i, a[N];

	srand((unsigned int) time(0));
	for (i = 0; i < N; i++) {
		a[i] = rand() % 10 + 1;
		printf(" %d", a[i]);
	}
	printf("\n");
	printf("Delete the item: %d\n", (i = rand() % 10 + 1));
	delrepeat(a, i);
	for (i = 0; i < N; i++)
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}
