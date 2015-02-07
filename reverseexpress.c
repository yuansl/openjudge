#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *a;

double eval(void)
{
	double x = 0;
	while (isspace(*a))
		a++;
	
	if (*a == '*') {
		a++;
		return eval() * eval();
	}
	if (*a == '+') {
		a++;
		return eval() + eval();
	}
	x = atof(a);
	while (*a != ' ')
		a++;
	return x;
}

int main(void)
{
	a = "* + 11.0 12.0  + 24.0 35.0";
	printf("%f\n", eval());
	return 0;
}
