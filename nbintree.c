#include <stdio.h>
#include <stdlib.h>

struct tnode {
	int key;
	struct tnode *left, *right;
};

struct stack_node {
	struct tnode *tnode;
	struct stack_node *next;
};

struct stack_node *stack;

void init_stack(void)
{
	stack = NULL;
}

void push(struct tnode *tn)
{
	struct stack_node *x = (struct stack_node *) malloc(sizeof(*x));
	x->tnode = tn;
	x->next = stack;
	stack = x;
}

struct tnode *pop(void)
{
	struct tnode *ret = stack->tnode;
	struct stack_node *tmp = stack;
	stack = stack->next;
	free(tmp);
	return ret;
}

int empty(void)
{
	return stack == NULL;
}

struct tnode *create_tnode(int key)
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
	T = create_tnode(key);
	T->left = create_tree();
	T->right = create_tree();
	return T;
}

int count_tree_node(struct tnode *t)
{
	int ct = 0;
	if (t) {
		init_stack();
		push(t);
		while (!empty()) {
			t = pop();
			printf(" %d", t->key);
			ct++;
			if (t->right)
				push(t->right);
			if (t->left)
				push(t->left);
		}
	}
	return ct;
}

void destroy_tree(struct tnode *t)
{
	if (t) {
		if (t->left)
			destroy_tree(t->left);
		if (t->right)
			destroy_tree(t->right);
		free(t);
	}
}

int main(void)
{
	struct tnode *tree = create_tree();
	int count = count_tree_node(tree);

	printf("\nThere are %d tree nodes of the tree\n", count);
	destroy_tree(tree);
	return 0;
}
