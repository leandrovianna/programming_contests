#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> g[], int comp[], int x) {
	for (int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		if (comp[v] == -1) {
			comp[v] = comp[x];
			dfs(g, comp, v);
		}
	}
}

void flow(vector<int> g[], int visit[], int x) {
	if (g[x].size() > 0) {
		int v = g[x][0];
		if (!visit[v]) {
			visit[v] = 1;
			flow(g, visit, v);
		}
		else {
			visit[v]++;
			return;
		}
	}

}

int main() {
	const int N = 1e4;
	int n, x, y, comp[N], visitas[N];
	vector<int> g[N];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
	}

	for (int i = 0; i < n; i++) {
		visitas[i] = 0;
	}

	visitas[0] = 1;
	flow(g, visitas, 0);

	string res = "S";

	if (visitas[0] == 1) {
		res = "N";
	}

	for (int i = 0; i < n; i++) {
		if (!visitas[i]) {
			res = "N";
			break;
		}
	}

	cout << res << endl;
	return 0;
}
