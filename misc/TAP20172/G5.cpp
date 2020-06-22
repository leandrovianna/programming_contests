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

const int MOD = 1e9+7;
const int MT = 60, ML = 1e5+10;
int T, M, N;

int dp[MT][ML];
int used[MT][ML], vis = 1;

int solve(int t, int l) {
	if (t == T) return 1;

	int &ans = dp[t][l];

	if (used[t][l] == vis) return ans;
	used[t][l] = vis;

	if (l == M) return ans = solve(t+1, l+1) % MOD;
	if (l == N) return ans = solve(t+1, l-1) % MOD;
	else return ans = 
		(solve(t+1, l+1) % MOD + solve(t+1, l-1) % MOD) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
		
	cin >> T >> M >> N;

	int resp = 0;
	for (int i = M; i <= N; i++)
		resp = (resp % MOD + solve(1, i) % MOD) % MOD;

	cout << resp << endl;
	return 0;
}
