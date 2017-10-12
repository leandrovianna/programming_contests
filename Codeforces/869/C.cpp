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

const int N = 5050;
const int MOD = 998244353;

int64_t comb[N][N], fac[N];

int64_t calc(int n, int m) {
	int a = min(n, m);

	int64_t ans = 0;
	for (int i = 0; i <= a; i++) {
		int64_t x = ((comb[n][i] % MOD * comb[m][i] % MOD) % MOD
			* fac[i] % MOD) % MOD;
		ans = (x + ans) % MOD;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
		
	for (int i = 0; i < N; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++)
			comb[i][j] = (comb[i-1][j-1] % MOD + comb[i-1][j] % MOD) % MOD;
	}

	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = (i * fac[i-1] % MOD) % MOD;

	int a, b, c;
	cin >> a >> b >> c;

	int ans = ((calc(a,b) % MOD * calc(b,c) % MOD) % MOD
			* calc(a,c) % MOD) % MOD;

	cout << ans << endl;
	return 0;
}
