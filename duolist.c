#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int key;
	int freq;
	struct node *prev, *next;
};

struct list {
	struct node *head, *tail;
};

struct node *create_node(int key)
{
	struct node *nd = (struct node *) malloc(sizeof(*nd));
	nd->key = key;
	nd->freq = 0;
	nd->prev = nd->next = NULL;
	return nd;
}

bool empty(struct list *list)
{
	return list->head->next == list->head;
}

struct list *create_list(void)
{
	struct list *list = (struct list *) malloc(sizeof(*list));
	list->head = create_node(0);
	list->tail = list->head;
	list->head->prev = list->tail;
	list->tail->next = list->head;
	return list;
}

void insert(struct list *list, int key)
{
	struct node *x = create_node(key);
	x->next = list->tail->next;
	x->prev = list->tail;
	list->tail = (list->tail->next = x);
	list->head->prev = list->tail;
}

bool delete(struct list *list, int key)
{
	struct node *curr = list->head->next;

	while (curr != list->head && curr->key != key)
		curr = curr->next;
	if (curr == list->head)
		return false;
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	if (curr == list->tail)
		list->tail = curr->prev;
	free(curr);
	return true;
}

struct node *find(struct list *list, int key)
{
	struct node *curr = list->head->next;
	while (curr != list->head && curr->key != key)
		curr = curr->next;
	if (curr == list->head)
		return NULL;
	return curr;
}

void visit(struct list *list)
{
	struct node *curr = list->head->next;

	while (curr != list->head) {
		printf(" %d", curr->key);
		curr = curr->next;
	}
	printf("\n");
}

void locate(struct list *list, int x)
{
	if (list != NULL) {
		struct node *curr = find(list, x);
		struct node *tmp = curr;

		if (curr == NULL)
			return;
		curr->freq++;
		while (curr->prev != list->head
		       && tmp->freq > curr->prev->freq)
				curr = curr->prev;
		if (tmp->prev == list->head || tmp == curr)
			return;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		if (tmp == list->tail)
			list->tail = tmp->prev;
		tmp->prev = curr->prev;
		tmp->next = curr;
		curr->prev->next = tmp;
		curr->prev = tmp;
		visit(list);
	}
}

void destroy(struct list *list)
{
	if (list != NULL) {
		struct node *curr;
		while (!empty(list)) {
			curr = list->head->next;
			delete(list, curr->key);
		}
		free(list->head);
	}
	free(list);
}

int main(void)
{
	struct list *L = create_list();
	int in;

	printf("inserting into the list: ");
	while (scanf("%d", &in) == 1)
		insert(L, in);
	visit(L);
	do {
		printf("locate function: ");
		if (scanf("%d", &in) != 1) {
			printf("invalid input!\n");
			break;
		}
		locate(L, in);
		visit(L);
	} while (true);
	destroy(L);
	return 0;
}
