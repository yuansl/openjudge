#include <stdio.h>
#include <string.h>

struct query {
	char q[2];
	int i;
};

int main(void)
{
	int i, j, ct, N, M;

	scanf("%d%d", &N, &M);

	struct query query[M];
	int a[N];

	for (i = 0; i < N && scanf("%d", &a[i]) == 1; i++)
		;
	for (i = 0; i < M && scanf("%s%d", query[i].q, &query[i].i) == 2; i++)
		;
	for (i = 0; i < M; i++) {
		ct = 0;
		if (strcmp("Q", query[i].q) == 0) {
			for (j = 0; j < N; j++)
				if (1 << query[i].i & a[j])
					ct++;
			printf("%d\n", ct);
		} else {
			for (j = 0; j < N; j++)
				a[j]++;
		}
	}

	return 0;
}
