//HackerRank - Keko the Brilliant - WOC 12 F
#include <bits/stdc++.h>
using namespace std;

const int N = 200'100, INF = numeric_limits<int>::max();
int r[N];
bool visited[N];
int sub_min[N];
vector<int> graph[N];

void dfs(int i, int p) {
	sub_min[i] = INF;

	for (const auto& u : graph[i]) {
		if (u == p) continue;

		dfs(u, i);

		int x = min(sub_min[u], r[u]);
		sub_min[i] = min(sub_min[i], x);
	}
}

int bfs(int i) {
	int changes = 0;

	queue<pair<int, int> > q;
	q.push({i, -1});

	while (!q.empty()) {
		int v = q.front().first;
		int p = q.front().second;

		q.pop();

		if (r[v] > sub_min[v]) {
			changes++;
			if (v == 1)
				r[v] = 1;
			else
				r[v] = sub_min[p];
		}

		for (const auto& u : graph[v]) {
			if (u == p) continue;

			q.push({u, v});
		}
	}

	return changes;
}

unordered_map<int, int> memo[N];

int solve(int i, int p, int x) {

	if (memo[i].find(x) != memo[i].end())
		return memo[i][x];

	int answer = 0;

	for (const auto &u : graph[i]) {
		if (u == p) continue;

		int y = solve(u, i, x) + 1;

		if (r[u] >= x)
			answer += min(y, solve(u, i, r[u]));
		else
			answer += y;
	}

	return memo[i][x] = answer;
}

int main() {
	ios::sync_with_stdio(false);
	int n, a, b;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> r[i];

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << min(solve(1, -1, 0) + 1, solve(1, -1, r[1])) << endl;

	return 0;
}
