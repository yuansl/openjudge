#include <stdio.h>
#include <string.h>

/* Insert SUBSTR into STR where the char value is maximum of the STR */
void string_insert(char *str, const char *substr)
{
	char *cur, *p, tmp, buf[16];

	p = str;
	cur = str + 1;
	while (*cur) {
		if (*cur > *p)
			p = cur;
		cur++;
	}
	tmp = p[1];
	p[1] = '\0';
	strcpy(buf, str);
	strcat(buf, substr);
	p[1] = tmp;
	strcat(buf, p + 1);
	strcpy(str, buf);	
}

int main(void)
{
	char str[11], substr[4];

	scanf("%s%s", str, substr);
	string_insert(str, substr);
	printf("%s\n", str);
	return 0;
}
