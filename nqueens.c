#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4
int queenrow[N + 1];

void place(int k, int i, int *result)
{
	int j;
	for (j = 1; j < k; j++) {
		if (queenrow[j] == i ||
		    abs(queenrow[j] - i) == abs(k - j)) {
			*result = false;
			return;
		} 
	}
	*result = true;
}

void print(int *a)
{
	int i, j;
	for (i = 1; i <= N; i++, putchar('\n'))
		for (j = 1; j <= N; j++)
		printf(" %d", queenrow[i] == j ? 1 : 0);
	printf("\n");
}

void nqueens(int k)
{
	int i, result;
	for (i = 1; i <= N; i++) {
		place(k, i, &result);
		if (result == true) {
			queenrow[k] = i;
			if (k == N) 
				print(queenrow);
			else
				nqueens(k + 1);
		}
	}
}

int main(void)
{
	int i;
	for (i = 1; i <= N; i++)
		queenrow[i] = 0;
	nqueens(1);
	return 0;
}
