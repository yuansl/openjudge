#include <stdio.h>
#include <stdlib.h>

int lg(int n)
{
	if (n == 1)
		return 0;
	else
		return 1 + lg(n / 2);
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: a.out <N>\n");
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);
	printf("lg(%d) = %d\n", n, lg(n));
	return 0;
}
