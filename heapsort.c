#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT(i) (i << 1)
#define RIGHT(i) ((i << 1) + 1)
#define PARENT(i) (i >> 1)
#define exch(x, y) { int tmp = x; x = y; y = tmp; }

int N = 0;
int heap_size = 0;

void heapify(int heap[], int i)
{
	int largest;
	if (LEFT(i) <= heap_size && heap[LEFT(i)] > heap[i])
		largest = LEFT(i);
	else
		largest = i;
	if (RIGHT(i) <= heap_size && heap[RIGHT(i)] > heap[largest])
		largest = RIGHT(i);
	if (largest != i) {
		exch(heap[i], heap[largest]);
		heapify(heap, largest);
	}
}

void build_max_heap(int heap[], int l, int r)
{
	int i;
	for (i = heap_size / 2; i >= 1; i--)
		heapify(heap, i);
}

void heap_sort(int heap[], int l, int r)
{
	int i;
	build_max_heap(heap, l, r);
	for (i = heap_size; i > 1; i--) {
		exch(heap[1], heap[heap_size]);
		heap_size--;
		heapify(heap, 1);
	}
}

int main(int argc, char *argv[])
{
	srand((unsigned int) time(0));
	if (argc != 2) {
		fprintf(stderr, "usage: a.out N\n");
		exit(EXIT_FAILURE);
	}
	N = atoi(argv[1]);
	int i, a[N + 1];

	heap_size = N;
	for (i = 1; i <= N; i++) {
		a[i] = rand() % N + 1;
		printf(" %d", a[i]);
	}
	printf("\n");
	heap_sort(a, 1, N);
	for (i = 1; i <= N; i++)
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}
