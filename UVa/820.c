#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
#define FALSE 0
#define TRUE 1

typedef unsigned int uint;

#define N 110
#define INF ((1<<30)-1)

void initAdjMatrix(long adj[][N], uint n) {
	uint i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			adj[i][j] = 0;
}

/** Queue Implementation **/
typedef struct {
	int first, second;
} pair;

typedef struct cel {
	pair p;
	struct cel* next;
} node;

node *new_queue_node(pair p) {
	node* n = (node*) malloc(sizeof(node));
	n->p = p;
	n->next = NULL;
	return n;
}

void queue_new(node **f, node **r) {
	*f = *r = NULL;
}

int queue_empty(node *f) {
	return (f == NULL);
}

void queue_push(node **f, node **r, pair p) {
	node *n = new_queue_node(p);
	if (*f == NULL) *f = *r = n;
	else {
		(*r)->next = n;
		*r = n;
	}
}

void queue_pop(node **f, node **r, pair *p) {
	if (!queue_empty(*f)) {
		node *tmp = *f;
		*p = (*f)->p;
		*f = (*f)->next;
		if (*f == NULL) *r = NULL;
		free(tmp);
	}
}

void queue_delete(node **f, node **r) {
	pair p;
	while (!queue_empty(*f)) {
		queue_pop(f, r, &p);
	}
}

/** end Queue Implementation **/

long find_min(long adj[][N], int parent[], int t) {
	int u = t;
	long minimum = INF;

	while (parent[u] != -1) {
		if (adj[parent[u]][u] < minimum) 
			minimum = adj[parent[u]][u];

		u = parent[u];
	}

	return minimum;
}

long ford_fulkerson(long adj[][N], uint n, int source, int sink) {
	node *f, *r;
	int v, i, u;
	int parent[N]; 
	bool visited[N];
	long minimum_flow = INF, max_flow = 0;

	while (minimum_flow > 0) {
		queue_new(&f, &r);

		for (i = 0; i < n; i++) {
			visited[i] = FALSE;
			parent[i] = -1;
		}

		/* push source to queue */
		pair curr = {source, 0};
		visited[source] = TRUE;
		v = source;
		queue_push(&f, &r, curr);

		while (!queue_empty(f)) {
			queue_pop(&f, &r, &curr);
			v = curr.first;
			
			if (v == sink) break;

			for (i = 0; i < n; i++) {
				if (adj[v][i] > 0 && visited[i] == FALSE) {
					parent[i] = v;
					visited[i] = TRUE;
					curr.first = i;
					queue_push(&f, &r, curr);
				}
			}
		}

		minimum_flow = 0;

		if (v == sink) {
			/* find minimum flow in path from source to sink */
			minimum_flow = find_min(adj, parent, sink);

			/* decrease and increase flow in edges */
			u = sink;
			while (parent[u] != -1) {
				adj[parent[u]][u] -= minimum_flow;
				adj[u][parent[u]] += minimum_flow;
				
				u = parent[u];
			}

			max_flow += minimum_flow;
		}

		queue_delete(&f, &r);
	}

	return max_flow;
}

int main() {
	uint n, m, i, k;
	int a, b, source, sink;
	long adj[N][N], c;

	k = 1;
	while (scanf("%u", &n), n) {
		initAdjMatrix(adj, n);

		scanf("%d %d %u", &source, &sink, &m);
		source--;
		sink--;

		for (i = 0; i < m; i++) {
			scanf("%d %d %ld", &a, &b, &c);
			a--;
			b--;
			adj[a][b] += c;
			adj[b][a] += c;
		}


		c = ford_fulkerson(adj, n, source, sink);
		printf("Network %u\nThe bandwidth is %ld.\n\n", k, c);
		k++;
	}

	return 0;
}
