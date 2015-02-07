#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	struct node *next;
};

typedef struct node * List;

struct node *create_node(int item)
{
	struct node *x = (struct node *) malloc(sizeof(*x));
	x->item = item;
	x->next = NULL;
	return x;
}

List create_list(void)
{
	return NULL;
}

inline int empty(List list)
{
	return list == NULL;
}

List insert(List list, int item)
{
	struct node *x, *prev, *curr;

	x = create_node(item);
	prev = curr = list;
	if (list == NULL)
		list = x;
	prev = curr;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
	}
	if (prev != NULL)
		prev->next = x;
	return list;
}

List delete(List list, int key)
{
	struct node *tmp, *prev, *curr = list;

	prev = curr;
	while (curr != NULL) {
		if (curr->item == key) {
			tmp = curr;
			curr = curr->next;
			prev->next = curr;
			if (tmp == list)
				list = curr;
			free(tmp);
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	return list;
}

void visit(List list)
{
	struct node *curr = list;
	while (curr != NULL) {
		printf(" %d", curr->item);
		curr = curr->next;
	}
	printf("\n");
}

void destroy(List list)
{
	struct node *curr;
	static int ct = 0;
	do {
		curr = list;
		if (curr != NULL)
			list = delete(list, curr->item);
		ct++;
	} while (!empty(list));
}

int main(void)
{
	List list = create_list();
	int in, ret;

	printf("Inserting into the list: ");
	while (scanf("%d", &in) == 1)
		list = insert(list, in);
	visit(list);

	do {
		printf("input for deleting: ");
		if ((ret = scanf("%d", &in)) != 1) {
			printf("warinning: invalid input!\n");
			break;
		}
		list = delete(list, in);
		if (!empty(list))
			visit(list);
		else
			printf("warnning: The list is empty now!\n");
	} while (!empty(list));
	destroy(list);
	return 0;
}
