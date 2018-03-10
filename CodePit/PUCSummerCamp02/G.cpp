//CodePit - Maximum Sum - G
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
int mat[N][N];
int pre[N][N];

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
			pre[i][j] = mat[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = i; k <= n; k++) {
				for (int h = j; h <= n; h++) {
					int mx = pre[k][h]
						+ pre[i-1][j-1] - pre[k][j-1] - pre[i-1][h];

					ans = max(ans, mx);
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
