//Codeforces - Points, Lines and Ready-made Titles - 872E
#include <bits/stdc++.h>
using namespace std;

const int N = 3*1e5;
vector<int> g[N];

int main() {
	ios::sync_with_stdio(false);
	int n, x, y;
	const int LIM = 1e5+10;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		g[x].push_back(LIM+y);
		g[LIM+y].push_back(x);
	}

	
	return 0;
}
