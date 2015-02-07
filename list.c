#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int key;
	struct node *next;
};

struct list {
	struct node *head, *tail;
};

struct node *create_node(int key)
{
	struct node *node = (struct node *) malloc(sizeof(*node));
	node->key = key;
	node->next = NULL;
	return node;
}

bool empty(struct list *list)
{
	return list->head->next == NULL;
}

struct list *create_list(void)
{
	struct list *list = (struct list *) malloc(sizeof(struct list));
	list->head = create_node(0);
	list->tail = list->head;
	return list;
}

void insert(struct list *list, int key)
{
	if (list != NULL) {
		struct node *node = create_node(key);
		struct node *curr = list->head;

		while (curr->next != NULL && curr->next->key < key)
			curr = curr->next;
		node->next = curr->next;
		curr->next = node;
	}
}

void insert2(struct list *list, int key)
{
	if (list != NULL) {
		struct node *node = create_node(key);
		list->tail = (list->tail->next = node);
	}
}

struct node *find(struct list *list, int item)
{
	if (list != NULL) {
		struct node *curr = list->head->next;
		while (curr != NULL && curr->key != item)
			curr = curr->next;
		return curr;
	}
	return NULL;
}

void delete(struct list *list, struct node *p)
{
	struct node *curr = list->head;

	while (curr != NULL && curr->next != p)
		curr = curr->next;
	if (curr != NULL && p != NULL) {
		curr->next = p->next;
		free(p);
	}
}

/* delete: delete the item which is (item > mintk && item < maxk) */
void delete2(struct list *list, int mink, int maxk)
{
	struct node *tmp, *curr = list->head->next;
	while (curr != NULL) {
		if (curr->key > mink && curr->key < maxk) {
			tmp = curr;
			curr = curr->next;
			delete(list, tmp);
			continue;
		}
		curr = curr->next;
	}
}

int exchange(struct list *list, struct node *p)
{
	if (list != NULL) {
		struct node *tmp = p->next;
		struct node *curr = list->head;

		while (curr != NULL && curr->next != p)
			curr = curr->next;
		if (tmp) {
			p->next = tmp->next;
			tmp->next = p;
			curr->next = tmp;
			return true;
		}
		return false;
	}
	return false;
}

void visit(struct list *list)
{
	if (list != NULL) {
		printf("visit:\n");
		struct node *curr = list->head->next;
		if (curr == NULL)
			printf("shit\n");
		while (curr != NULL) {
			printf(" %d", curr->key);
			curr = curr->next;
		}
		printf("\n");
	}
}

void destroy(struct list *list)
{
	if (list != NULL) {
		struct node *tmp, *curr = list->head;
		while (curr != NULL) {
			tmp = curr;
			curr = curr->next;
			free(tmp);
		}
	}
	free(list);
}

int main(void)
{
	struct list *list = create_list();
	struct node *p;
	int val, mink, maxk;

	while (scanf("%d", &val) == 1)
		insert2(list, val);
	visit(list);
	printf("Delete the item: ");
	scanf("%d", &val);
	p = find(list, val);
	if (p)
		delete(list, p);
	visit(list);
	printf("Exchange node: ");
	scanf("%d", &val);
	p = find(list, val);
	if (p)
		printf("Exchange: %s\n", exchange(list, p) ? "true" : "false");
	visit(list);
	printf("Delete the item which is greater than mink: ");
	scanf("%d", &mink);
	printf("and less than maxK: ");
	scanf("%d", &maxk);
	delete2(list, mink, maxk);
	visit(list);
	destroy(list);
	return 0;
}
