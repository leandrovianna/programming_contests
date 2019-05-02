#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

const int INF = numeric_limits<int>::max();
const int64_t LLINF = numeric_limits<int64_t>::max();
const int V = 50; // number of vertex

// augment - walk in augmented path and update flow
// adj - adj matrix, p - parent of vertex i, t - sink
int64_t augment(int64_t adj[][V], int p[], int t) {
	int u = t;
	int64_t minimum = LLINF;

	// find minimum flow in augmented path
	while (p[u] != -1) {
		minimum = min(adj[p[u]][u], minimum);
		u = p[u];
	}

	// walk in augment path updating flow
	u = t;
	while (p[u] != -1) {
		adj[p[u]][u] -= minimum;
		adj[u][p[u]] += minimum;
		u = p[u];
	}

	return minimum; // return minimum flow in augmented path
}

// s - source, t - sink, n - number of vertex
int64_t edmonds_karp(int64_t adj[][V], const int s, const int t, const int n) {

	int64_t mf = 0, // max flow answer
			f = 1;
	int dist[V];
	int p[V];
	int u;

	while (f > 0) {
		f = 0;
		for (int i = 0; i < n; i++) dist[i] = INF, p[i] = -1;
		dist[s] = 0;

		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			u = q.front();
			q.pop();

			// stop if reach sink t
			if (u == t) break;

			for (int v = 0; v < n; v++) {
				if (adj[u][v] > 0 && dist[v] == INF) {
					dist[v] = dist[u] + 1, q.push(v), p[v] = u;
				}
			}
		}

		// verify if bfs stop when reach sink t
		if (u == t) {

			// find minimum flow in augmented path
			f = augment(adj, p, t);

			// update max flow of network
			mf += f;
		}
	}

	return mf;
}

void zero_matrix(int64_t m[][V], const int n, int64_t x = 0) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			m[i][j] = x;
}

int main() {
	ios::sync_with_stdio(false);

	int64_t adj[V][V];
	int n = 38;
	int source = 0, sink = 37;
	int64_t num_apps;

	string line;

	while (getline(cin, line)) {

		zero_matrix(adj, n);
		num_apps = 0;

		do {
			int app = line[0] - 'A' + 1;
			adj[source][app] += line[1] - '0';
			num_apps += line[1] - '0';

			for (int i = 3; line[i] != ';'; i++) {
				adj[app][line[i] - '0' + 27] = INF;
			}
			getline(cin, line);
		} while (!line.empty());

		// add edges computer -> sink
		for (int i = 0; i < 10; i++)
			adj[27 + i][sink] = 1;

		int64_t mf = edmonds_karp(adj, source, sink, n);

		if (mf == num_apps) {
			for (int i = 0, j; i < 10; i++) {
				for (j = 1; j <= 26; j++) {
					if (adj[27 + i][j] == 1) {
						cout << (char)('A' + j - 1);
						break;
					}
				}
				if (j > 26)
					cout << '_';
			}
			cout << "\n";
		}
		else cout << "!\n";
	}

	return 0;
}
