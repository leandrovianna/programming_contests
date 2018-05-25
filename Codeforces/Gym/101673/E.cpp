#include <bits/stdc++.h>
using namespace std;

const int N = 550;

map<string, int> idx;
bool mark[N][2];
vector<pair<int, int> > g[N];

void dfs(int i, int j) {
	mark[i][j] = true;

	for (const auto &p : g[i]) {
		int u = p.first;
		if (p.second == 0 && !mark[u][j]) {
		    dfs(u, j);
        }

        if (p.second == 1 && !mark[u][1]) {
            dfs(u, 1);
        }
	}
}

int cnt = 10;
int push(string cls) {
    if (idx.count(cls) == 0) {
        idx[cls] = cnt++;
    }

    return idx[cls];
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	string a1, a2, op;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a1 >> op >> a2;
        push(a1);
        push(a2);

		if (op == "is-a") {
			g[push(a1)].push_back({push(a2), 0});
		} else {
			g[push(a1)].push_back({push(a2), 1});
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a1 >> op >> a2;

		memset(mark, 0, sizeof(mark));

		dfs(push(a1), 0);

		cout << "Query " << i+1 << ": ";

		if (op == "is-a") {
			if (mark[push(a2)][0]) {
				cout << "true\n";
			} else {
				cout << "false\n";
			}
		} else {
			if (mark[push(a2)][1]) {
				cout << "true\n";
			} else {
				cout << "false\n";
			}
		}
	}

	return 0;
}
