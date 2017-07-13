#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

const int N = 1010;

int main() {
	int g[N][N];	
	int n, m;
	char c;

	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			g[i][j] = (c == '#') ? 1 : 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!g[i][j]) continue;

			if (i == 0 || j == 0 || j == m-1 || i == n-1)
				g[i][j] = 2;
			else if (!g[i-1][j]) 
				g[i][j] = 2;
			else if (!g[i+1][j])
				g[i][j] = 2;
			else if (!g[i][j-1])
				g[i][j] = 2;
			else if (!g[i][j+1])
				g[i][j] = 2;
		}
	}

	int qtd = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 2) qtd++;
		}
	}

	cout << qtd << endl;
	return 0;
}
