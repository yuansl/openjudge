#include <stdio.h>

struct student {
	char name[40];
	int month;
	int day;
	int visit;
};

int main(void)
{
	int i, j, n;

	scanf("%d", &n);
	struct student stu[n];
	i = 0;
	while (i < n) {
		scanf("%s%d%d", stu[i].name, &stu[i].month, &stu[i].day);
		stu[i].visit = 0;
		i++;
	}
	for (i = 0; i < n; i++) {
		if (stu[i].visit == 1)
			continue;
		printf("%d %d %s ", stu[i].month, stu[i].day, stu[i].name);
		stu[i].visit = 1;
		for (j = i + 1; j < n; j++)
			if (stu[j].month == stu[i].month &&
			    stu[j].day == stu[i].day &&
			    stu[j].visit == 0) {
				printf("%s ", stu[j].name);
				stu[j].visit = 1;
			}
		putchar('\n');
	}
	return 0;
}
