#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, row, col, r, c;
	int **a;

	scanf("%d%d", &row, &col);

	a = (int **) malloc(row * sizeof(int *));

	for (i = 0; i < row; i++)
		a[i] = (int *) malloc(col * sizeof(int));
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			scanf("%d", &a[i][j]);
	for (j = 0; j < col; j++) {
		r = 0; 
		c = j;
		while (r < row && c >= 0) {
			printf("%d\n", a[r][c]);
			r++;
			c--;
		}
	}
	for (i = 1; i < row; i++) {
		r = i;
		c = col - 1;
		while (r < row) {
			printf("%d\n", a[r][c]);
			r++;
			c--;
		}
	}
	for (i = 0; i < row; i++)
		free(a[i]);
	free(a);
	return 0;
}
