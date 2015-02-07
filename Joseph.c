#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	int inode;
};

struct node *node_alloc(int val)
{
	struct node *x = malloc(sizeof(*x));
	x->inode = val;
	return x;
}

int main(void)
{
	struct node head, *x, *t;
	int i, n, m;
	
	scanf("%d%d", &n, &m);
	printf("%d %d\n", n, m);
		
	head.next = NULL;
	t = &head;
	for (i = 1; i <= n; i++) {
		x = node_alloc(i);
		x->next = t->next;
		t = (t->next = x);
	}
	t->next = head.next;
	x = t->next;
	while (x != x->next) {
		for (i = 1; i < m - 1; i++)
			x = x->next;
		t = x->next;
		x->next = t->next;
		free(t);
		x = x->next;
	}
	printf("%d\n", x->inode);
	free(x);

	return 0;
}
