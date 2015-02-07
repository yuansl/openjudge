#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[100][100], replace[100], rreplace[100];
	int i, n;

	n = 0;
	while (n < 100 && scanf("%s", str[n]) == 1) {
		n++;
		if (getchar() == '\n')
			break;
	}
	scanf("%s%s", replace, rreplace);
	for (i = 0; i < n; i++)
		if (strcmp(str[i], replace) == 0) {
			memset(str[i], 0, strlen(str[i]));
			strcpy(str[i], rreplace);
		}
	for (i = 0; i < n; i++)
		printf(" %s", str[i]);
	printf("\n");
	return 0;
}
