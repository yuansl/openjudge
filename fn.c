#include <stdio.h>

double f(n)
{
	if (n < 1)
		return -1;
	if (n == 1)
		return 1.0;
	else
		return f(n - 1) + (double) 1 / n;
}

int main(void)
{
	int n, ret;

	while ((ret = scanf("%d", &n)) == 1)
		printf("f(%d) = %f\n", n, f(n));
	return 0;
}
