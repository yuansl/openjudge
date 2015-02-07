#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

double stof(const char *s)
{
	double x = 0.0, y = 0.0;
	int i, d;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '.')
			break;
		if (isdigit(s[i]))
			x = 10 * x + (s[i] - '0');
		else if (s[i] != '.') {
			fprintf(stderr, "Error: invalid input: %s\n", s);
			exit(EXIT_FAILURE);
		}
	}
	if (x > 0 && s[i] == '.') {
		i++;
		d = 1;
		while (s[i] != '\0') {
			if (!isdigit(s[i])) {
				fprintf(stderr, "Error: invalid input: %s\n", s);
				exit(EXIT_FAILURE);
			}
			y += (s[i] - '0') / pow(10, d);
			d++;
			i++;
		}
	}
	return (x += y);
}

int main(void)
{
	char exp[BUFSIZ];

	scanf("%40s", exp);
	printf("%f\n", stof(exp));
	return 0;
}
