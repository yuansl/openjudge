#include <stdio.h>
#include <limits.h>

#define V 6

void init_graph(int graph[][V + 1])
{
	int u, v, w;

	for (u = 1; u <= V; u++)
		for (v = 1; v <= V; v++)
			graph[u][v] = INT_MAX;

	while (scanf("%d%d%d", &u, &v, &w) == 3) {
		graph[u][v] = w;
		graph[v][u] = w;
	}
}

void dijkstra(int graph[][V + 1], int dist[], int s)
{
	int i, j, min, visit[V + 1];

	for (i = 0; i <= V; i++) {
		dist[i] = INT_MAX;
		visit[i] = 0;
	}
	dist[s] = 0;
	visit[s] = 1;
	for (i = 1; i <= V; i++) {
		if (i == s)
			continue;
		if (graph[s][i] != INT_MAX && graph[s][i] < dist[i])
			dist[i] = graph[s][i];
	}
	for (j = 1; j < V; j++) {
		min = 0;
		for (i = 1; i <= V; i++)
			if (visit[i] == 0 && dist[i] < dist[min])
				min = i;

		visit[min] = 1;
		for (i = 1; i <= V; i++) {
			if (visit[i] == 0 && graph[min][i] != INT_MAX
			    && dist[min] + graph[min][i] < dist[i])
				dist[i] = dist[min] + graph[min][i]; 
		}
	}
}

int main(void)
{
	FILE *fp = freopen("input", "r", stdin);
	int i, j, graph[V + 1][V + 1], dist[V + 1];

	init_graph(graph);
	printf("dist");
	for (j = 1; j <= V; j++)
		printf(" %2d", j);
	printf("\n");
	for (i = 1; i <= V; i++) {
		dijkstra(graph, dist, i);
		printf("%d: ", i);
		for (j = 1; j <= V; j++)
			printf(" %2d", dist[j]);
		printf("\n");
	}
	fclose(fp);
	return 0;
}
