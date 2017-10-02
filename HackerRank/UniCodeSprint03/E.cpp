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

enum Color {
	SemCor = 0,
	Branco,
	Preto
};

vector<int> g[N];
Color colors[N];
int dp1[N];
int dp2[N];
int used1[N];
int used2[N];
int vis = 1;

int solve1(int v, int p);
int solve2(int v, int p);

int factor = 1;

int solve1(int v, int p) {

	if (used1[v] == vis) return dp1[v];
	used1[v] = vis;

	int ans = (colors[v] == Branco) ? factor : -factor;

	if (g[v].size() == 1 && p != -1) return dp1[v] = ans;

	for (auto &u : g[v]) {
		if (u == p) continue;

		int x = solve1(u, v);
		ans += max(x, 0);
	}


	return dp1[v] = ans;
}

int solve2(int v, int p) {

	if (used2[v] == vis) return dp2[v];
	used2[v] = vis;

	int ans = 0;

	if (g[v].size() == 1 && p != -1) return ans;

	for (auto &u : g[v]) {
		if (u == p) continue;
		ans = max(ans, max(solve1(u,v), solve2(u,v)));
		// ans = maxabs(ans, maxabs(solve1(u, v), solve2(u, v)));
	}

	return dp2[v] = ans;
}

set<int> subtree;

void gen_subtree(int v, int p, bool flag) {

	if (dp1[v] <= 0) return;

	if (flag || dp1[v] >= dp2[v]) {
		subtree.insert(v);

		for (auto &u : g[v]) {
			if (u == p) continue;

			if (dp1[u] > 0)
				gen_subtree(u, v, true);
		}
	}
	else {
	// nao coloca v
		for (auto &u : g[v]) {
			if (u == p) continue;

			if (dp1[u] == dp2[v]) {
				gen_subtree(u, v, true);
				break;
			} else if (dp2[u] == dp2[v]) {
				gen_subtree(u, v, false);
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
			
	int n;
	int a, b, c;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		colors[i] = (c ? Preto : Branco);
	}
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	factor = 1;
	// testando pra branco = +1 e preto = -1
	int ans1 = max(solve1(1, -1), solve2(1, -1));

	// gera subtree
	gen_subtree(1, -1, false);

	// testando pra branco = -1 e preto = +1
	vis++;
	factor = -1;
	int ans2 = max(solve1(1, -1), solve2(1, -1));

	// se ans2 for maior, gera nova subtree
	if (ans2 > ans1) {
		subtree.clear();
		gen_subtree(1, -1, false);
	}

	cout << max(ans1, ans2) << endl;
	cout << subtree.size() << endl;
	for (auto it = subtree.begin(); it != subtree.end(); it++) {
		cout << *it;
		if (next(it) != subtree.end())
			cout << " ";
	}

	return 0;
}
