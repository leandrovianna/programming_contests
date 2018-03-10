//CodePit - Breaking String - H
//LiveArchive - '' - 6439
#include <bits/stdc++.h>
using namespace std;

const int M = 1000 + 10;
int cuts[M];
int dp[M][M];

int main() {
	ios::sync_with_stdio(false);
	int n, m;

	while (cin >> n >> m) {
		cuts[0] = 0;
		for (int i = 1; i <= m; i++) {
			cin >> cuts[i];
		}
		cuts[m+1] = n;
	}

	return 0;
}
