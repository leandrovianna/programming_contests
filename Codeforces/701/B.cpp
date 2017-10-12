#include <iostream>
using namespace std;

typedef unsigned long long int64;

typedef struct {
	int x, y;
} Point;

int main() {
	const int N = 1e5+1, M = 1e5;
	int column[N], row[N];
	int n, m, rows_ocp, col_ocp;
	int64 cells;
	Point rooks[M];

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> rooks[i].x >> rooks[i].y;

	for (int i = 1; i < n+1; i++)
		column[i] = row[i] = 0;

	cells = (int64) n * n;
	rows_ocp = col_ocp = 0;
	for (int i = 0; i < m; i++) {
		int x = rooks[i].x;
		int y = rooks[i].y;

		if (!row[x]) {
			cells -= n-col_ocp;
			rows_ocp++;
		}

		if (!column[y]) {
			cells -= n-rows_ocp;
			col_ocp++;
		}

		row[x] = 1;
		column[y] = 1;

		cout << cells;
		if (i != n) cout << ' ';
		else cout << endl;
	}
	return 0;
}
