#include <stdio.h>
#include <stdlib.h>

struct stones {
	char *message;
	struct stones *next;
};

char *win_or_lose(int a, int b)
{
	int tmp = a / b;
	if (a >= b && tmp >= 2)
		return "win\n";
	else 
		return "lose\n";
}

struct stones *node(int a, int b)
{
	struct stones *x = (struct stones *) malloc(sizeof *x);
	x->message = win_or_lose(a, b);
	x->next = NULL;
	return x;
}

int main(void)
{
	int a, b;
	struct stones head, *x;

	head.next = NULL;
	x = &head;
	while (scanf("%d%d", &a, &b) == 2 && a * b != 0)
		x = (x->next = node(a, b));

	while (head.next != NULL) {
		x = head.next;
		printf("%s", x->message);
		head.next = x->next;
		free(x);
	}
	return 0;
}
