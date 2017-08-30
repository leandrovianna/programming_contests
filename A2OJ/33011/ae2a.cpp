//SPOJ - AE2A
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

const int N = 700;
const int MAXV_DICE = 6;
const int K = MAXV_DICE * N + 10;

int n, k;
double dp[N][K];

int main() {
	ios::sync_with_stdio(false);
	int t;	

	dp[0][0] = 1;
	for (int i = 1; i < N; i++)
		dp[i][0] = 0;
	for (int j = 1; j < K; j++)
		dp[0][j] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < K; j++) {
			dp[i][j] = 0;
			for (int x = 1; x <= MAXV_DICE; x++)
				if (i-1 >= 0 && j-x >= 0) dp[i][j] += 1/6.0 * dp[i-1][j-x];
		}
	}

	cin >> t;
	while (t--) {
		cin >> n >> k;

		if (n >= N || k >= K) cout << 0 << endl;
		else {
			cout << (int) (100 * dp[n][k]) << endl;
		}
	}
	return 0;
}
