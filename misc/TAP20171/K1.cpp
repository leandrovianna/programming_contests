#include <iostream>
#include <queue>
using namespace std;

#define M 1000

int dist[M][M];
const int W = 1;
const int I[] = {0, -1, 0, 1};
const int J[] = {-1, 0, 1, 0};

void bfs(char grid[][M], const int si, const int sj, const int m) {
	queue<pair<int, int> > queue;
	pair<int, int> p;
	int vi, vj, ni, nj;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			dist[i][j] = -1;

	queue.push(make_pair(si, sj));
	dist[si][sj] = 0;
	
	while (!queue.empty()) {
		vi = queue.front().first;
		vj = queue.front().second;
		queue.pop();

		for (int k = 0; k < 4; k++) {
			ni = vi+I[k];
			nj = vj+J[k];

			if ((0 <= ni && ni < m) && (0 <= nj && nj < m)
					&& grid[ni][nj] == '-') {

				int new_dist = dist[vi][vj] + W;
				if (dist[ni][nj] == -1 || dist[ni][nj] > new_dist) {
					dist[ni][nj] = new_dist;
					queue.push(make_pair(ni, nj));
				}
			}
		}
	}
}

int main() {
	int n, m;
	char grid[M][M];

	cin >> n;
	for (int ni = 0; ni < n; ni++) {
		cin >> m;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				cin >> grid[i][j];

		grid[m-1][m-1] = '-';
		bfs(grid, 0, 0, m);

		cout << dist[m-1][m-1] << endl;
	}
	return 0;
}
