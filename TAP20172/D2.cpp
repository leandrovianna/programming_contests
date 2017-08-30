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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 600;
const int INF = 1e9;
const int I[] = {0, 1, -1, 0};
const int J[] = {-1, 0, 0, 1};

int n, m, grid[N][N], dist[N][N];

iii piii(int w, int i, int j) {
	return make_pair(w, make_pair(i, j));
}

void dijkstra(int si, int sj) {
	priority_queue<iii> queue;
	bool visited[N][N];

	queue.push(piii(0, si, sj));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j] = INF, visited[i][j] = false;
	dist[si][sj] = 0;

	int vi, vj, ni, nj;

	while (!queue.empty()) {
		vi = queue.top().second.first;
		vj = queue.top().second.second;
		queue.pop();

		if (visited[vi][vj]) continue;
		visited[vi][vj] = true;

		for (int k = 0; k < 4; k++) {
			ni = vi + I[k] * grid[vi][vj];
			nj = vj + J[k] * grid[vi][vj];

			if (0 <= ni && ni < n && 0 <= nj && nj < m
				&& dist[ni][nj] > dist[vi][vj] + 1) {
				dist[ni][nj] = dist[vi][vj] + 1;
				queue.push(piii(-dist[ni][nj], ni, nj));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	char ch;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ch, grid[i][j] = ch - '0';

	dijkstra(0, 0);

	if (dist[n-1][m-1] == INF)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << dist[n-1][m-1] << endl;
	return 0;
}
