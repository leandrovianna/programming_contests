// Codeforces - Divisors - 1033D Div2
#include <bits/stdc++.h>
using namespace std;
 
map<int64_t, int> factors;
map<int64_t, int> freq;
const int M = 2000100;
bool prime[M];

void sieve(int n) {
    assert(n < M);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; i++)
        prime[i] = true;

    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            for (int j = i+i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    int n; 
    int64_t x;
    const int N = 1500000;
    bool found;
    sieve(N);

    int64_t ans = 1;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        freq[x]++;
    }

    int aux = -1;

    for (const auto &p : freq) {
        x = p.first;
        found = false;
        for (int64_t e = 2; e < N; e++) {
            if (e * e * e * e > x)
                break;

            if (prime[e] && e * e * e * e == x) {
                factors[e] += 4 * p.second;
                found = true;
                break;
            }
        }

        if (found)
            continue;

        int64_t lo = 2;
        int64_t hi = N;
        int64_t mid;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int64_t v = mid * mid * mid;
            if (v == x) {
                if (prime[mid]) {
                    factors[mid] += 3 * p.second;
                    found = true;
                }

                break;
            }
            
            if (v < x) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        if (found)
            continue;

        lo = 2;
        hi = 2000000000;
        
        while (lo <= hi) {
            mid = (hi - lo) / 2 + lo;
            int64_t v = mid * mid;
            if (v == x) {
                // note: not need verify if mid is prime
                // mid should be a prime
                factors[mid] += 2 * p.second;
                found = true;

                break;
            }
            
            if (v < x) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        if (found)
            continue;

        set<int64_t> gcds;
        for (const auto &p2 : freq) {
            int64_t v = __gcd(p2.first, x);
            if (v > 1 && v != x) {
                gcds.insert(v);
            }
        }

        for (const auto &v : gcds) {
            factors[v] += p.second;
        }

        if (gcds.size() == 0) {
            factors[aux--] += p.second;
            factors[aux--] += p.second;
        } else if (gcds.size() == 1) {
            factors[aux--] += p.second;
        }
    }

    int64_t mod = 998244353;
    for (const auto &f : factors) {
        ans = (ans * (f.second+1)) % mod;
    }

    cout << ans << endl;
    return 0;
}
