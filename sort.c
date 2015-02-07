#include <stdio.h>
#include <string.h>

#define MAXLEN 20
#define MAXSIZE 10

#define swap(str1, str2) ({ char tmp[MAXLEN]; strcpy(tmp, str1); \
			strcpy(str1, str2); strcpy(str2, tmp); })

int main(void)
{
	int pass, ct, j;
	char line[MAXSIZE][MAXLEN];
	char tmp[MAXLEN];

	ct = 0;
	while (ct < MAXSIZE && scanf("%s", tmp) != EOF) {
		strcpy(line[ct], tmp);
		ct++;
	}
	for (pass = 1; pass < ct; pass++)
		for (j = 0; j < ct - 1; j++)
			if (strcmp(line[j], line[j + 1]) > 0) {
				swap(line[j], line[j + 1]);
			}
	for (pass = 0; pass < ct; pass++)
		puts(line[pass]);
	return 0;
}
