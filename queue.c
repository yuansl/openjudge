#include <stdio.h>
#include <stdlib.h>

static int *que;
static int front, tail;
static int q_size;

void q_init(int n)
{
	que = (int *) malloc(n * sizeof(int));
	q_size = n;
	front = tail = 0;
}

int q_empty(void)
{
	return front == tail;
}

int q_full(void)
{
	return (tail + 1) % q_size == front;
}

void q_put(int val)
{
	if (!q_full()) {
		printf("The value %d is inserted into the queue.\n", val);
		tail %= q_size;
		que[tail] = val;
		tail++;
	}
}

int q_get(void)
{
	int tmp = -1;
	if (!q_empty()) {
		tmp = que[front];
		front = (front + 1) % q_size;
	}
	return tmp;
}

int q_capacity(void)
{
	int ct = 0;
	int i;

	for (i = front; i < tail; i = (i + 1) % q_size)
		ct++;
	return ct;
}

int main(void)
{
	q_init(15);
	while (!q_full()) 
		q_put(rand() % 100);

	printf("The capacity of the queue now is: %d\n", q_capacity());
	return 0;
}
