#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

int main(void)
{
	int i, j, n, k, a[MAXSIZE];

	scanf("%d%d", &n, &k);
	int max[n], min[n];
	i = 0; 
	while (i < n && scanf("%d", &a[i]) == 1)
		i++;
	for (i = 0; i <= n - k; i++) {
		max[i] = a[i];
		min[i] = a[i];
		for (j = 1; j < k; j++) {
			if (a[i + j] > max[i])
				max[i] = a[i + j];
			if (a[i + j] < min[i])
				min[i] = a[i + j];
		}
	}
	for (i = 0; i <= n - k; i++)
		printf(" %d", min[i]);
	printf("\n");
	for (i = 0; i <= n - k; i++)
		printf(" %d", max[i]);
	printf("\n");
	return 0;
}
