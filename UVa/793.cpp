//UVa - Network Connections - 793
#include <bits/stdc++.h>
using namespace std;

namespace UF {
	const int N = 1000010;
	int parent[N];
	void init(int sz) {
		for (int i = 0; i < sz; i++)
			parent[i] = i;
	}
	int find(int x) {
		if (parent[x] == x) return x;
		else return parent[x] = find(parent[x]);
	}
	bool isSameSet(int x, int y) {
		return find(x) == find(y);
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
	int t;
	string line;

	cin >> t;
	cin.get();
	cin.get();

	while (t--) {
		int n, a, b;
		cin >> n;

		UF::init(n+1);

		char ch;
		int succAns = 0,
			unsuccAns = 0;

		cin.ignore();

		while (getline(cin, line) && line.size() > 0) {
			istringstream istream(line);

			istream >> ch >> a >> b;

			if (ch == 'c') {
				UF::join(a, b);
			} else {
				if (UF::isSameSet(a, b))
					succAns++;
				else
					unsuccAns++;
			}
		}

		cout << succAns	<< "," << unsuccAns << endl;

		if (t > 0)
			cout << endl;
	}

	return 0;
}
