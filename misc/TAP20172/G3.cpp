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

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	const int N = 60;
	char grid[N][N];
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'o' && grid[i+1][j] == '.') {
					flag = true;
					grid[i+1][j] = 'o';
					grid[i][j] = '.';
				}
			}
		}
	}

	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < m; j++)
			cout << grid[i][j];

	return 0;
}
