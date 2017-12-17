//HackerRank - Red Knight's Shortest Path - WCS12
#include <bits/stdc++.h>
using namespace std;

const int N = 210;
int dist[N][N];

const int I[] = {-2, -2, +0, +2, +2, +0};
const int J[] = {-1, +1, +2, +1, -1, -2};
const string NAME[] = {"UL", "UR", "R", "LR", "LL", "L"};

void bfs(int si, int sj, int n) {
	queue<pair<int, int> > queue;
	queue.push({si, sj});

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = -1;

	dist[si][sj] = 0;

	while (!queue.empty()) {
		int vi = queue.front().first;
		int vj = queue.front().second;

		queue.pop();

		for (int k = 0; k < 6; k++) {
			int di = vi + I[k];
			int dj = vj + J[k];

			if (0 <= di && di < n && 0 <= dj && dj < n
					&& dist[di][dj] == -1) {
				dist[di][dj] = 1 + dist[vi][vj];
				queue.push({di, dj});
			}
		}
	}
}

vector<int> findPath(int i, int j, int n) {
	if (dist[i][j] > 0) {
		for (int k = 5; k >= 0; k--) {
			int di = i - I[k];
			int dj = j - J[k];

			if (0 <= di && di < n && 0 <= dj && dj < n
					&& dist[di][dj] == dist[i][j]-1) {
				auto path = findPath(di, dj, n);
				path.push_back(k);
				return path;
			}
		}

		return vector<int>();
	} else {
		return vector<int>();
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	int i0, j0, i1, j1;

	cin >> n
		>> i0 >> j0
		>> i1 >> j1;

	bfs(i0, j0, n);

	if (dist[i1][j1] == -1)
		cout << "Impossible" << endl;
	else {
		cout << dist[i1][j1] << endl;
		auto path = findPath(i1, j1, n);
		for (const auto &dir : path) {
			cout << NAME[dir] << " ";
		}
		cout << endl;
	}

	return 0;
}
