#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, tmp, n, *a;

	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(*a));
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0, j = n - 1; i < j; i++, j--) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	for (i = 0; i < n; i++)
		printf(" %d", a[i]);
	printf("\n");
	free(a);
	return 0;
}
