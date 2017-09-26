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

const int N = 1e5+10;

vector<int> g[N];
int n, cor = 0;
bool visited[N];

void dfs(int i, bool c) {
	if (c == false) cor++;

	visited[i] = true;

	for (auto &u : g[i]) {
		if (!visited[u]) dfs(u, !c);
	}
}

int main() {
	ios::sync_with_stdio(false);
		
	int a, b;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cor = 0;
	// sai do 1, cor false
	dfs(1, false);
	
	// cout << cor << " " << e << endl;
	i64 ans = ((long long)cor) * abs(cor - n);
	ans -= n - 1;
	cout << ans << endl;
	return 0;
}
