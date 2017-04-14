#include <iostream>
#include <queue>
using namespace std;

#define N 1000
#define M 1000

int dist[N][M];
const int I[] = {0, 1};
const int J[] = {1, 0};

void bfs(int grid[][M], const int si, const int sj, const int n, const int m) {
	queue<pair<int, int> > queue;
	int vi, vj, ni, nj;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j] = -1;

	queue.push(make_pair(si, sj));
	dist[si][sj] = grid[si][sj];
	
	while (!queue.empty()) {
		vi = queue.front().first;
		vj = queue.front().second;
		queue.pop();

		for (int k = 0; k < 2; k++) {
			ni = vi+I[k];
			nj = vj+J[k];

			if ((0 <= ni && ni < n) && (0 <= nj && nj < m)) {

				int new_dist = dist[vi][vj] + grid[ni][nj];
				if (dist[ni][nj] == -1 || dist[ni][nj] < new_dist) {
					dist[ni][nj] = new_dist;
					queue.push(make_pair(ni, nj));
				}
			}
		}
	}
}

int main() {
	int k, n, m;
	int grid[N][M];

	cin >> k;
	while (k--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> grid[i][j];
		
		bfs(grid, 0, 0, n, m);

		cout << dist[n-1][m-1] << endl;
	}
	return 0;
}
