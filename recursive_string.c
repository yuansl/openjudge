#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
	char s[100];
	int i, j, flag;

	scanf("%s", s);
	flag = true;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			flag = false;
			break;
		}
	}
	if (flag) 
		printf("%d\n", 1);
	else
		printf("%d\n", 0);
	return 0;
}
