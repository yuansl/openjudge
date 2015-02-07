#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i, n, prev_state, curr_state;
	char prev_ch, curr_ch, (*array)[200], *p;

	scanf("%d", &n);
	array = (char (*)[200]) malloc(n * sizeof(char [200]));
	while ((curr_ch = getchar()) != '\n')
		continue;
	for (i = 0; i < n; i++)
		fgets(array[i], 200 * sizeof(char), stdin);

	for (i = 0; i < n; i++) {
		p = array[i];
		prev_state = 1;
		curr_state = 1;
		curr_ch = *p;
		prev_ch = *p;
		p++;
		while (*p != '\0') {
			if (*p == curr_ch) {
				curr_state++;
				if (curr_state > prev_state) {
					prev_state = curr_state;
					if (curr_ch != prev_ch)
						prev_ch = curr_ch;
				}
			} else {
				curr_ch = *p;
				curr_state = 1;
			}
			p++;
		}
		printf("%c %d\n", prev_ch, prev_state);
	}
	free(array);
	return 0;
}
