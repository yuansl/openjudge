#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	int stunum;
	char name[40];
	char sex[2];
	int age;
	int grade;
	char addr[40];
	struct student *next;
};

struct student *new_node(void)
{
	struct student *s = (struct student *) malloc(sizeof(struct student));
	s->next = NULL;
	return s;
}

struct student *reverse(struct student *list)
{
	struct student *head, *curr, *n;

	if (list == NULL)
		return list;
	head = list;
	curr = head->next;
	head->next = NULL;
	while (curr != NULL) {
		n = curr->next;
		curr->next = head;
		head = curr;
		curr = n;
	}
	return head;
}

int main(void)
{
	char buf[BUFSIZ];
	struct student *prev, *curr, *list = NULL;

	memset(buf, 0, BUFSIZ);
	while (fgets(buf, BUFSIZ, stdin) != NULL && strcmp(buf, "end\n") != 0) {
		if (list == NULL) {
			list = new_node();
			curr = list;
		} else 
			curr = (curr->next = new_node());
		sscanf(buf, "%d %s %s %d %d %s",
		       &curr->stunum, curr->name, curr->sex,
		       &curr->age, &curr->grade, curr->addr);
		memset(buf, 0, BUFSIZ);
	}

	list = reverse(list);
	curr = list;
	printf("After input:\n");
	while (curr != NULL) {
		printf("%d %s %s %d %d %s\n", curr->stunum, curr->name,
		       curr->sex, curr->age, curr->grade, curr->addr);
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	return 0;
}
