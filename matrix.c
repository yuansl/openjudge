#include <stdio.h>
#include <stdlib.h>

struct array {
	int row;
	int col;
};

int main(void)
{
	int i, j, n, r, c, row, col, sum;
	int ***a;
	struct array *x;

	scanf("%d", &n);
	a = (int ***) malloc(n * sizeof(int **));
	x = (struct array *) malloc(n * sizeof(*x));
	for (i = 0; i < n; i++) {
		scanf("%d%d", &row, &col);
		x[i].row = row;
		x[i].col = col;
		a[i] = (int **) malloc(r * sizeof(int *));
		for (j = 0; j < row; j++)
			a[i][j] = (int *) malloc(col * sizeof(int));
		for (r = 0; r < row; r++)
			for (c = 0; c < col; c++)
				scanf("%d", &a[i][r][c]);
	}
	for (i = 0; i < n; i++) {
		row = x[i].row;
		col = x[i].col;
		sum = 0;
		for (r = 0; r < row; r++)
			sum += a[i][r][0] + a[i][r][col - 1];
		for (c = 1; c < col - 1; c++)
			sum += a[i][0][c] + a[i][row - 1][c];
		printf("%d\n", sum);
	}

	for (i = 0; i < n; i++) {
		row = x[i].row;
		col = x[i].col;
		for (r = 0; r < row; r++)
			free(a[i][r]);
		free(a[i]);
	}
	free(a);
	free(x);
	return 0;
}
