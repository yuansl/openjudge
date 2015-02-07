#include <stdio.h>
#include <stdlib.h>

struct expression {
	int x;
	int y;
	struct expression *next;
};

struct expression *create_node(int x, int y)
{
	struct expression *node = (struct expression *)
		malloc(sizeof(struct expression));
	node->x = x;
	node->y = y;
	node->next = NULL;
	return node;
}

int main(void)
{
	FILE *fp = freopen("expfile", "r", stdin);
	struct expression *(*exp)[300], *tmp; 
	int x, y, i, j, n, N;

	scanf("%d", &n);
	N = 2 * n;
	exp = (struct expression *(*)[300]) 
		malloc(N * sizeof(struct expression *[300]));
	for (i = 0; i < N; i++)
		for (j = 0; j < 300; j++)
			exp[i][j] = create_node(0, 0);

	for (i = 0; i < N; i++) {
		j = -1;
		while (scanf("%d%d", &x, &y) == 2) {
			if (y < 0)
				break;
			y %= 301;
			if (y > j)
				j = y;
			tmp = create_node(x, y);
			tmp->next = exp[i][y]->next;
			exp[i][y]->next = tmp;
			tmp = exp[i][y]->next;
		}
		exp[i][0]->y = j;
	}
	for (i = 0; i < N; i += 2) {
		y = ((exp[i][0]->y > exp[i+1][0]->y) 
		     ? exp[i][0]->y : exp[i+1][0]->y);

		for (j = y; j >= 0; j--) {
			x = 0;
			tmp = exp[i][j]->next;
			while (tmp != NULL) {
				x += tmp->x;
				tmp = tmp->next;
			}
			tmp = exp[i+1][j]->next;
			while (tmp != NULL) {
				x += tmp->x;
				tmp = tmp->next;
			}
			if (x != 0)
				printf("[ %d %d ] ", x, j);
		}
		printf("\n");
	}
	fclose(fp);
	return 0;
}
