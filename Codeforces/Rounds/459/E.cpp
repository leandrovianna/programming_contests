//Codeforces - Pashmak and Graph - 459E
#include <bits/stdc++.h>
using namespace std;

const int N = 300'010;
int dp[N];
int tmp[N];
vector<pair<int,int> > edge[N];

int main() {
	ios::sync_with_stdio(false);
	int n, m, a, b, w;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		edge[w].push_back({a,b});
	}

	for (int wi = 0; wi < N; wi++) {
		for (auto &e : edge[wi]) {
			int u = e.first, v = e.second;
			tmp[v] = max(tmp[v], dp[u] + 1);
		}

		for (auto &e : edge[wi]) {
			int v = e.second;
			dp[v] = max(dp[v], tmp[v]);
		}
	}

	cout << *max_element(dp, dp+n+1) << endl;
	return 0;
}
