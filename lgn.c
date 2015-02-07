#include <stdio.h>

double lg(n)
{
	if (n < 1)
		return -1;
	if (n == 1)
		return 0.0;
	else
		return 1 + lg(n / 2);
}

int main(void)
{
	int n;

	while (scanf("%d", &n) == 1) 
		printf("lg(%d) = %g\n", n, lg(n));
	return 0;
}
