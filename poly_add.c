#include <stdio.h>
#include <stdlib.h>

struct poly {
	int x;
	int y;
};

int compar(const void *a, const void *b)
{
	return ((struct poly *) b)->y - ((struct poly *) a)->y;
}

int main(void)
{
	int n, i, j, k;
	struct poly **array, *p;
	struct poly test[] = {
		{ -1, 17 }, { 2, 20 }, { 5, 9 }, { -9, 22 }, { -7, 7 }, { 0, -1 }
	};

	p = calloc(300, sizeof(*p));

	scanf("%d", &n);
	array = malloc(2 * n * sizeof(*array));
	
	n *= 2;
	for (i = 0; i < n; i++)
		array[i] = calloc(300, sizeof(struct poly));

	for (i = 0; i < n; i++) {
		for (j = 0; j < 300; j++) {
			scanf("%d%d", &array[i][j].x, &array[i][j].y);
			if (array[i][j].y < 0)
				break;
		}
		qsort(array[i], m, sizeof(struct poly), compar);
	}

	i = j = k = 0;
	while (array[0][i].y >= 0 && array[0][j].y >= 0) {
		if (array[0][i].y > array[0][j].y) {
			p[k++] = array[0][i++];
		} else if (array[0][i].y == array[0][j].y) {
			p[k] = array[0][i];
			p[k].x = array[0][i].x + array[0][j].x;
			k++;
		} else {
			p[k++] = 
		}
	}
	for (i = 0; i < n; i++)
		free(array[i]);
	free(array);

	qsort(test, sizeof(test)/sizeof(test[0]), sizeof(test[0]), compar);
	for (i = 0; i < sizeof(test)/sizeof(test[0]); i++)
		printf(" [%d %d]", test[i].x, test[i].y);
	printf("\n");
	return 0;
}
