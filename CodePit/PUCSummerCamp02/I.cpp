#include <bits/stdc++.h>
using namespace std;

const int N = 100100, MOD = 5000000;

int64_t ft[55][N];

void update(int x, int k, int64_t v) {
	for (; x < N; x += x & -x) {
		ft[k][x] += v;
	}
}

int64_t query(int x, int k) {
	int64_t v = 0;
	for (; x > 0; x -= x & -x) {
		v += ft[k][x];
		v %= MOD;
	}
	return v;
}

int n, k;

int main() {
	ios::sync_with_stdio(false);
	int x;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		x++;
		update(x, 1, 1);

		for (int j = 2; j <= k; j++) {
			update(x, j, query(x-1, j-1));
		}
	}

	cout << query(N-1, k) << endl;
	return 0;
}
