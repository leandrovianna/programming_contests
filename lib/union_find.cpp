#include <bits/stdc++.h>
using namespace std;

namespace UF {
	const int N = 1010;
	int parent[N];
	void init(int sz) {
		for (int i = 0; i < sz; i++)
			parent[i] = i;
	}
	int find(int x) {
		if (parent[x] == x) return x;
		else return parent[x] = find(parent[x]);
	}
	void join(int x, int y) {
		x = find(x);
		y = find(y);

		if (x != y)
			parent[x] = y;
	}
}

int main() {
	ios::sync_with_stdio(false);

	return 0;
}
