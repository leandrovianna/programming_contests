#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define N 255
#define K N

typedef unsigned long int uint64;

vector<vector<vector<uint64> > > dp;

uint64 solve(int n, int k, int ant) {
	if (k == 1) {
		if (n >= ant)
			return 1;
		else
			return 0;
	}
	else if (dp[n][k][ant] != -1)
		return dp[n][k][ant];
	else {
		uint64 s = 0;
		for (int i = ant; i <= n-k+1; i++) {
			s += solve(n-i, k-1, i);
		}

		return dp[n][k][ant] = s;
	}
}

int main() {
	int n, k, res;	

	cin >> n >> k;

	dp.resize(N);
	for (int i = 0; i <= n; i++) {
		dp[i].resize(K);
		
		for (int j = 0; j <= k; j++) {
			dp[i][j].resize(N);
			for (int l = 0; l <= n; l++)
				dp[i][j][l] = -1;
		}
	}

	cout << solve(n, k, 1) << endl;
	return 0;
}
