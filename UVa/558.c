#include <stdio.h>
#include <string.h>

#define N 1000
#define M 2000
#define INF ((1<<16)-1)

typedef char bool;
#define TRUE 1
#define FALSE 0

struct t_edge {
	int to, from, weight;
};

bool bellmanford(struct t_edge edges[M], int s, int n, int m, long dist[]) {
	int i, j, k;
	struct t_edge e;

	for (i = 0; i < n; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;

	for (k = 0; k < n-1; k++) {
		for (i = 0; i < m; i++) {
			e = edges[i];
			if (dist[e.from] > dist[e.to] + e.weight) {
				dist[e.from] = dist[e.to] + e.weight;
			}
		}
	}

	for (i = 0; i < m; i++) {
		e = edges[i];
		if (dist[e.from] > dist[e.to] + e.weight) {
			return FALSE;
		}
	}

	return TRUE;
}

int main() {
	int n, m, c, i;
	long dist[N];
	int from, to, weight;
	struct t_edge edges[M];

	scanf("%d", &c);

	while (c-- > 0) {
		scanf("%d %d", &n, &m);

		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &from, &to, &weight);
			edges[i].from = from;
			edges[i].to = to;
			edges[i].weight = weight;
		}

		if (bellmanford(edges, 0, n, m, dist))
			printf("not possible\n");
		else
			printf("possible\n");
	}

	return 0;
}
