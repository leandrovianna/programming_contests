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

const int N = 1e5 + 10;

int main() {
	vector<int> g[N];
	int n, m;
	int t, a, b;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> t >> a >> b;
		if (t == 0) {
			if (find(g[a].begin(), g[a].end(), b) != g[a].end())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else {
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}

	return 0;
}
