#include <stdio.h>

#define N 100

void factor(int n, int *ct)
{
	int j, x = 2;
	for (j = n / 2; j >= x; j--) {
		if (n % j == 0) {
			(*ct)++;
			factor(j, ct);
			x = n / j + 1;
		}
	}
}

int main(void)
{
	int n, i, ct, a[N];

	scanf("%d", &n);
	for (i = 0; i < n && scanf("%d", &a[i]) == 1; i++)
		;
	n = i;
	i = 0;
	while (i < n) {
		ct = 1;
		factor(a[i], &ct);
		printf("%d\n", ct);
		i++;
	}
	return 0;
}
