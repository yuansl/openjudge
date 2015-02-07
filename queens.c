#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int n;

bool place(int queenrow[], int k, int i, int *result)
{
	int j;
	for (j = 1; j < k; j++) {
		if (queenrow[j] == i
		    || abs(k - j) == abs(i - queenrow[j])) {
			return (*result = false);
		}
	}
	return (*result = true); 
}

void print(int queenrow[])
{
	int i, j;
	for (i = 1; i <= n; i++, putchar('\n'))
		for (j = 1; j <= n; j++)
			printf(" %d", queenrow[i] == j ? 1 : 0);
	printf("\n");
}

void nqueens(int queenrow[], int k)
{
	int i, result = 0;
	for (i = 1; i <= n; i++) {
		place(queenrow, k, i, &result);
		if (result) {
			queenrow[k] = i;
			if (k == n)
				print(queenrow);
			else
				nqueens(queenrow, k + 1);
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: a.out N\n");
		return -1;
	}
	n = atoi(argv[1]);
	int i, queenrow[n + 1];
	for (i = 1; i <= n; i++) 
		queenrow[i] = 0;
	nqueens(queenrow, 1);
	return 0;
}
