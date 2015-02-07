#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
	char str[11];
	char substr[4];
	struct string *next;
};

char *insert_substr(char str[], char substr[])
{
	char ch;
	int i, j;

	ch = str[0];
	j = 0;
	for (i = 1; str[i] != '\0'; i++)
		if (str[i] > ch) {
			ch = str[i];
			j = i;
		}
	j++;
	char tmp[strlen(str+j) + 1];
	strcpy(tmp, str + j);
	strcpy(str+j, substr);
	strcpy(str + j + strlen(substr), tmp);
	return str;
}

int main(void)
{
	struct string array, *x;
	char s[11], subs[4], *str;

	array.next = NULL;
	x = &array;
	while (scanf("%10s%3s", s, subs) == 2) {
		x = (x->next = (struct string *) malloc(sizeof(struct string)));
		x->next = NULL;
		strcpy(x->str, s);
		strcpy(x->substr, subs);
	}

	while (array.next != NULL) {
		x = array.next;
		str = insert_substr(x->str, x->substr);
		printf("%s\n", str);
		array.next = x->next;
		free(x);
	}
	return 0;
}
