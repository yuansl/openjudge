#include <stdio.h>
#include <math.h>

/* Pn(x) = ai * x ^i */
int pn(int a[], int n, int x)
{
	int i, sum;

	sum = 0;
	for (i = 0; i < n; i++)
		sum += a[i] * pow(x, i);
	return sum;
}

int main(void)
{

	return 0;
}
