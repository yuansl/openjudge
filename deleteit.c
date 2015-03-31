#include <stdio.h>
#include <stdlib.h>

struct nlist {
	int val;
	struct nlist *next;
};

struct nlist *alloc_node(int val)
{
	struct nlist *ret;

	ret = malloc(sizeof(*ret));
	ret->val = val;
	ret->next = NULL;
	return ret;
}

void delete_key(struct nlist *list_head, int key)
{
	struct nlist *p, *cur;

again:
	p = NULL;
	cur = list_head;
	while (cur && cur->val != key) {
		p = cur;
		cur = cur->next;
	}
	if (cur) {
		if (!p) {
			p = cur->next;
			list_head = p;
			free(cur);
			cur = p;
		} else {
			p->next = cur->next;
			free(cur);
		}
		goto again;
	}
}

void destroy_list(struct nlist *list_head)
{
	struct nlist *p, *cur;

	cur = list_head;
	while (cur) {
		p = cur;
		cur = cur->next;
		free(p);
	}
}

void output_list(struct nlist *list_head)
{
	struct nlist *cur = list_head;

	while (cur) {
		printf(" %d", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

int main(void)
{
	int m, n, i;
	struct nlist list_head, *x;

	scanf("%d", &n);
	list_head.next = NULL;
	x = &list_head;
	i = 0;
	while (i++ < n) {
		scanf("%d", &m);
		x->next = alloc_node(m);
		x = x->next;
	}

	scanf("%d", &m);
	delete_key(list_head.next, m);
	output_list(list_head.next);
	destroy_list(list_head.next);
	return 0;
}
