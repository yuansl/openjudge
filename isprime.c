#include <stdio.h>
#include <stdbool.h>

bool is_prime(int m)
{
	int n, flag = true;

	if (m < 2)
		return false;
	for (n = m / 2; n >= 2; n--)
		if (m % n == 0)
			return (flag = false);
	return flag;
}

int main(void)
{
	int n;

	while (scanf("%d", &n) == 1)
		printf(" is_prime(%d) : %s\n",
		       n, is_prime(n) == true ? "true" : "false");
	return 0;
}
