//Lib - Fenwick Tree 2D XOR
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int64_t dp[4][N][N];

int parity(int x, int y) {
	int res = 0;
	if (x % 2) res++;
	if (y % 2) res += 2;
	return res;
}

int64_t query(int x, int y) {
	int64_t res = 0;
	x++;
	y++;
	int whichSquare = parity(x, y);
	for (int i = x; i > 0; i -= (i & (-i))) {
		for (int j = y; j > 0; j -= (j & (-j))) {
			res ^= dp[whichSquare][i][j];
		}
	}
	return res;
}

void update(int x, int y, int64_t val) {
	x++;
	y++;
	int whichSquare = parity(x, y);
	for (int i = x; i <= N; i += (i & (-i))) {
		for (int j = y; j <= N; j += (j & (-j))) {
			dp[whichSquare][i][j] ^= val;
		}
	}
}

int query2d(int x1, int y1, int x2, int y2) {
    int r = query(x2, y2);
    r ^= query(x2, y1 - 1);
    r ^= query(x1 - 1, y2);
    r ^= query(x1 - 1, y1 - 1);
    return r;
}

void update2d(int x1, int y1, int x2, int y2, int val) {
    update(x1, y1, val);
    update(x1, y2 + 1, val);
    update(x2 + 1, y1, val);
    update(x2 + 1, y2 + 1, val);
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, p;
    int a, b, c, d;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p >> a >> b >> c >> d;

        update2d(a, b, c, d, p);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << query2d(i, j, i, j);
            if (j < n)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
