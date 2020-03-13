// Codeforces - Count the Arrays - 1312D
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int64_t fat[N];

int64_t exp(int64_t base, int64_t expo, int64_t mod) {
    int64_t ans = 1;
    
    while (expo > 0) {
        if (expo & 1) ans = (ans * base) % mod;
        
        base = (base * base) % mod;
        expo >>= 1;
    }
    
    return ans;
}

int64_t inv(int64_t x, int64_t mod) {
    return exp(x, mod-2, mod);
}

int64_t comb(int64_t n, int64_t k, int64_t mod) {
    int64_t r = fat[n];
    r = (r * inv(fat[n-k], mod)) % mod;
    r = (r * inv(fat[k], mod)) % mod;
    return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	
	cin >> n >> m;
	
	const int64_t mod = 998244353;
	
	fat[0] = 1;
	for (int i = 1; i < N; i++) {
	    fat[i] = (fat[i-1] * i) % mod;
	}
	
	int64_t p2 = 1;
	for (int i = 0; i < n-3; i++) {
	    p2 = (p2 * 2) % mod;
	}
	
	int64_t ans = comb(m, n-1, mod);
	ans = (ans * (n-2)) % mod;
	ans = (ans * p2) % mod;
	
	cout << ans << "\n";
	return 0;
}
