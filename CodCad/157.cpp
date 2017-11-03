//CodCad - Bolhas e Baldes
#include <bits/stdc++.h>
using namespace std;

const int N = 2*1e5+10;

int bit[N];

// execute the query [1, x]
int query(int x) {
	int s = 0;
	
	while (x) {
		s += bit[x];
		x -= (x & -x);
	}

	return s;
}

// execute the update [1,x]
void update(int x, int v) {
	while (x <= N) {
		bit[x] += v;
		x += (x & -x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	
	int n, x, ans;

	while (cin >> n, n) {
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			ans += i - query(x);
			update(x, 1);
		}

		cout << (ans % 2 ? "Marcelo" : "Carlos") << endl;

		memset(bit, 0, sizeof(bit));
	}

	return 0;
}
