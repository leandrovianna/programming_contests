//CodePit - Plant - J
#include <bits/stdc++.h>
using namespace std;

int64_t fastExp(int64_t base, int64_t exp, const int64_t MOD) {
	int64_t ans = 1LL;
	int64_t x = base;

	while (exp > 0) {
		if (exp & 1) {
			ans = (ans * x) % MOD;
			exp--;
		} else {
			x = (x * x) % MOD;
			exp >>= 1;
		}
	}

	return ans;
}
int main() {
	ios::sync_with_stdio(false);

	const int64_t mod = 1000000007;
	const int64_t inverse = 500000004; // multiplicative inverse
	int64_t n;
	cin >> n;

	int64_t ans = (fastExp(4LL, n, mod) + fastExp(2LL, n, mod)) % mod;
	ans = (ans * inverse) % mod;

	cout << ans << endl;

	return 0;
}
