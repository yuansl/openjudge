#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct tnode {
	int key;
	struct tnode *left, *right;
};

bool like(struct tnode *s, struct tnode *t)
{
	if (s == NULL && t == NULL)
		return true;
	if ((s == NULL && t != NULL)
	    || (s != NULL && t == NULL))
		return false;
	else
		return like(s->left, t->left) && like(s->right, t->right);
}

struct tnode *create_node(int key)
{
	struct tnode *x = (struct tnode *) malloc(sizeof(*x));
	x->key = key;
	x->left = x->right = NULL;
	return x;
}

struct tnode *create_tree(void)
{
	struct tnode *T = NULL;
	int key;

	scanf("%d", &key);
	if (key == 0)
		return T;
	T = create_node(key);
	T->left = create_tree();
	T->right = create_tree();
	return T;
}

void visit_tree(struct tnode *T)
{
	if (T) {
		printf(" %d", T->key);
		visit_tree(T->left);
		visit_tree(T->right);
	}
}

void destroy_tree(struct tnode *T)
{
	if (T) {
		if (T->left)
			destroy_tree(T->left);
		if (T->right)
			destroy_tree(T->right);
		free(T);
	}
}

int main(void)
{
	struct tnode *t1 = create_tree();
	struct tnode *t2 = create_tree();
	visit_tree(t1);
	printf("\n");
	visit_tree(t2);
	printf("\n");
	printf("like (head, tree) = %d\n", like(t1, t2));
	destroy_tree(t1);
	destroy_tree(t2);
	return 0;
}
