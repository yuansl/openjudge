#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, n0, q, k;

	while (scanf("%d%d", &n, &k) == 2) {
		q = log2(k / n);
		n0 = n * (int) pow(2, q);
		if (fabs(n0 - k) > fabs(n0 *2 - k)) 
			q += fabs(n0 * 2 - k) + 1;
		else
			q += fabs(n0 - k);
		printf("%d\n", q);
	}
	return 0;
}
