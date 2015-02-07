#include <stdio.h>

#define N 10000

int A[N][N] = {{0}};

int ack(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return ack(m - 1, 1);
	else
		return ack(m - 1, ack(m, n - 1));
}

int ack2(int m, int n)
{
	int i, j;

	if (m == 0)
		return n + 1;
	for (i = 0; i < N; i++)
		A[0][i] = i + 1;

	for (i = 0; i <= m; i++)
		for (j = 0; j <= n; j++)
			if (i == 0)
				A[i][j] = j + 1;
			else if (j == 0)
				A[i][j] = A[i - 1][1];
			else
				A[i][j] = A[i - 1][A[i][j - 1]];
	return A[m][n];
}

int main(void)
{
	int m, n;

	while (scanf("%d%d", &m, &n) == 2) {
		printf("ack(%d, %d) = %d\n", m, n, ack(m, n));
	}
	return 0;
}
