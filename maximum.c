#include <stdio.h>
#include <stdlib.h>

#define N 20

int main(void)
{
	double num[N] = { 4543.9, 4543.9, 3, 45, 654.7, 7, 66, 35, 45, 4,
			  6, 4543.9, 9, 4600, 46, 54, 6, 43, 5.980, 34 };
	int pos[N];
	int position = 0;
	int i, j = 1;

	for (i = 0; i < N; i++)
		printf(" %g", num[i]);
	printf("\n");
	for (i = 1; i < N; i++)
		if (num[i] > num[position]) {
			position = i;
			j = 1;
		} else if (num[i] == num[position])
			pos[j++] = i;
	pos[0] = position;
	if (j < N)
		pos[j] = -1;
	printf("The max number is: %3.2f\n", num[position]);
	printf("The location of the maximum is: ");
	for (i = 0; i < N; i++) {
		if (pos[i] == -1)
			break;
		printf("at position %d\n", pos[i]);
	}

	return 0;
}
