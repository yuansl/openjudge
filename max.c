#include <stdio.h>

#define exch(x, y) { int tmp = x; x = y; y = tmp; }

int main(void)
{
	int x, y, z;

	while (scanf("%d%d%d", &x, &y, &z) != EOF) {
		if (x > y)
			exch(x, y);
		if (x > z)
			exch(x, z);
		if (y > z)
			exch(y, z);
	}
	return 0;
}
