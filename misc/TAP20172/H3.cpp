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

const int M = 60;

int n, m;
int label = 0;
int comp[M][M];
char grid[M][M];

const int I[] = {-1, 0, 1, 0};
const int J[] = {0, -1, 0, 1};

void dfs(int i, int j) {

	for (int x = 0; x < 4; x++) {
		int xi = i+I[x];
		int xj = j+J[x];
		if (0 <= xi && xi < n && 0 <= xj && xj < m
				&& comp[xi][xj] == 0 && 
				(grid[xi][xj] == 'L' || grid[xi][xj] == 'C')) {
			comp[xi][xj] = comp[i][j];
			dfs(xi, xj);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

	label = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == 'L' && comp[i][j] == 0) {
				comp[i][j] = ++label;
				dfs(i, j);
			}

	cout << label << endl;
	return 0;
}
