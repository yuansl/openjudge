#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_k(int k, int a[], int *n)
{
	int i, j, *tmp;

	tmp = (int *) malloc((*n) * sizeof(int));
	memset(tmp, 0, (*n) * sizeof(int));
	for (i = 0, j = 0; i < *n; i++)
		if (a[i] != k)
			tmp[j++] = a[i];
	memset(a, 0, (*n) * sizeof(int));
	for (i = 0; i < j; i++)
		a[i] = tmp[i];
	*n = j;
	free(tmp);
}

int main(void)
{
	int i, k, n, *a;

	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(*a));

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	delete_k(k, a, &n);
	for (i = 0; i < n; i++)
		printf(" %d", a[i]);
	printf("\n");
	free(a);

	return 0;
}
