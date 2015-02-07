#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i, n, sum;
	char (*str)[40];

	scanf("%d", &n);
	str = (char (*)[40]) malloc(n * sizeof(*str));
	i = 0;
	while (i < n && scanf("%s", str[i]) == 1)
		i++;
	i = 0;
	sum = 0;
	while (i < n) {
		sum += strlen(str[i]);
		printf("%s", str[i]);
		i++;
		if (i == n) 
			break;
		if (sum + strlen(str[i]) < 80) {
			sum++;
			putchar(' ');
		} else {
			sum = 0;
			putchar('\n');
			continue;
		}
	}
	putchar('\n');
	free(str);
	return 0;
}
