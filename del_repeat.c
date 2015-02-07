#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *next;
};

struct node *new_node(int val)
{
	struct node *x = (struct node *) malloc(sizeof(struct node));
	x->key = val;
	x->next = NULL;
	return x;
}

int main(void)
{
	int ct, n, val;
	struct node *curr, *prev, *list = NULL;

	scanf("%d", &n);
	ct = 0;
	while (ct < n && scanf("%d", &val) != EOF) {
		if (list == NULL) {
			list = new_node(val);
			curr = list;
		} else {
			curr = (curr->next = new_node(val));
		}
		ct++;
	}
	scanf("%d", &val);
	curr = list;
	prev = curr;
	while (curr != NULL) {
		if (curr->key == val && curr == list) {
			list = curr->next;
			free(curr);
			curr = prev = list;
			continue;
		}
		if (curr->key == val) {
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
			continue;
		}
		prev = curr;
		curr = curr->next;
	}

	curr = list;
	while (curr != NULL) {
		printf(" %d", curr->key);
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	printf("\n");
	return 0;
}
