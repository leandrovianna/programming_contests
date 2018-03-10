//CodePit - ACORN - G
//UVa - ACORN - 1231
#include <bits/stdc++.h>
using namespace std;

const int T = 2010;
const int H = 2010;
int acorn[T][H];

int main() {
	ios::sync_with_stdio(false);

	int t, h, f;
	int c, a, x;
	int dp[H];

	cin >> c;
	while (c--) {
		cin >> t >> h >> f;
		memset(acorn, 0, sizeof(acorn));

		for (int i = 0; i < t; i++) {
			cin >> a;
			for (int j = 0; j < a; j++) {
				cin >> x;
				acorn[i][x]++;
			}
		}

		dp[h] = 0;
		for (int tree = 0; tree < t; tree++) {
			dp[h] = max(dp[h], acorn[tree][h]);
		}

		for (int height = h - 1; height >= 0; height--) {
			dp[height] = 0;
			for (int tree = 0; tree < t; tree++) {
				acorn[tree][height] +=
					max(acorn[tree][height + 1],
						(f + height <= h ? dp[f + height] : 0));

				dp[height] = max(dp[height], acorn[tree][height]);
			}
		}

		cout << dp[0] << endl;
	}

	cin >> c; // receive 0
	assert(c == 0);

	return 0;
}
