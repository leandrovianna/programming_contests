//HackerEarth - Breaking Edges
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
vector<int> g[N];
int c[N];
int sub[N];

int dfs(int v, int p) {
	sub[v] = c[v];

	for (const auto &u: g[v]) {
		if (u == p) continue;
		sub[v] |= dfs(u, v);
	}

	return sub[v];
}

int dfs2(int v, int p, int acc) {
	int tam = g[v].size();
	sort(g[v].begin(), g[v].end());
	int pref[tam+10];
	int sufix[tam+10];
	vector < int > filhos;

	for(int i = 0; i < tam+10; i++){
	    pref[i] = sufix[i] = 0;
	}

	for(int i = 1; i <= tam; i++) {
	    if (g[v][i-1] == p) continue;
		filhos.push_back(g[v][i-1]);
	}

	tam = filhos.size();
	for(int i = 1; i <= tam; i++) {
		int u = filhos[i-1];
		pref[i] |= pref[i-1] | sub[u];
	}

	for(int i = tam; i >= 1; i--) {
	    int u = filhos[i-1];
		sufix[i] |= sufix[i+1] | sub[u];
	}

	int ans = 0;
	for (int i = 1; i <= tam; i++) {
		int u = filhos[i-1];
		ans += dfs2(u, v, acc | pref[i-1] | sufix[i+1] | c[u])
		    + (sub[u] == (acc | pref[i-1] | sufix[i+1] ));
	}


	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int n, x, y;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	for (int i = 1; i < n; ++i)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0);

	cout << dfs2(1, 0, c[1]) << endl;
	return 0;
}
