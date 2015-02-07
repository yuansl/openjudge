#include <stdio.h>

int f(int n)
{
	int i, j, k, sum;

	sum = 0;
	for (i = 1; i <= n; i++) {
		for (j = n; j >= i; j--)
			for (k = 1; k <= j; k++)
				sum++;
		printf("sum = %d\n", sum);
	}
	return sum;
}

int main(void)
{
	printf("f(5) = %d\n", f(5));
	return 0;
}
