#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int N = 0;
static int lino = 1;

void print(char b[])
{
	int i;
	for (i = 0; i < N; i++)
		printf(" %c", b[i]);
	printf("\n");
}

void permutation(char a[], char b[], int n, int l, int r)
{
	int i, j, k;
	char c[n];

	if (l == r) {
		printf("%d:", lino);
		print(b);
		lino++;
		return;
	}

	for (i = l; i <= r; i++) {
		b[l] = a[i];
		for (j = l, k = l + 1; j <= r; j++) {
			if (j == i)
				continue;
			b[k++] = a[j];
		}
		for (k = l; k <= r; k++)
			c[k] = b[k];
		permutation(c, b, n, l + 1, r);
	}
}

int main(void)
{
	char a[BUFSIZ], b[BUFSIZ];

	printf("permutation for: ");
	while (scanf("%s", a) == 1) {
		lino = 1;
		N = strlen(a);
		permutation(a, b, N, 0, N - 1);
	}
	return 0;
}
