#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define ld long double
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, c)
 
using namespace std;
 
const int N = 13, K = 100, B = 1<<13;
 
int dp[B][N][K];
int used[B][N][K];
int vis = 1;
int d, n, k;
 
int solve(int bitmask, int i, int j) {
	if (j < 0) return 0;
	if (i == n) return (j == 0) ? 1 : 0;
 
	int &ans = dp[bitmask][i][j];
 
	int &us = used[bitmask][i][j];
 
	if (us == vis) return ans;
	else us = vis, ans = 0;
 
	for (int x = 0; x < n; x++) {
		if ((1<<x) & bitmask) continue;
 
		int maiores = __builtin_popcount(bitmask >> x);
	
		ans += solve((1<<x | bitmask), i+1, j - maiores);
	}
 
	return ans;
}
 
int main()
{
 
/*	dp[1][0] = 1;
	for (int i = 1; i < K; i++)
		dp[1][i] = 0;
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < K; j++) {
			dp[i][j] = 0;
			for (int x = max(0, j-(i-1)); x <= j; x++) 
				dp[i][j] += dp[i-1][x];
		}
	}*/
 
	cin >> d;
	while (d--) {
		cin >> n >> k;
 
		cout << solve(0, 0, k) << endl;
		vis++;
	}
 
	return 0;
}
