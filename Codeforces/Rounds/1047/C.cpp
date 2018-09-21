// Codeforces - Enlarge GCD - 1047C Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 15 * 1000 * 1000 + 10;
bool notprime[N];
int fp[N]; // smallest first prime factor
vector<int> primes;

void sieve(int n) {
    assert(n < N);
    notprime[0] = notprime[1] = true;

    for (int i = 2; i <= n; i++) {
        if (!notprime[i]) {
            fp[i] = i;
            for (int j = i+i; j <= n; j += i) {
                notprime[j] = true;
                fp[j] = i;
            }
            primes.push_back(i);
        }
    }
}

const int M = 3 * 1000 * 100 + 10;
int a[M];
int qt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(N-1);

    int n;

    cin >> n;

    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = (g == 0 ? a[i] : __gcd(a[i], g));
    }

    int exp;
    int ans = n;
    for (int i = 0; i < n; i++) {
        a[i] /= g;
        while (a[i] > 1) {
            int p = fp[a[i]];
            exp = 0;
            if (a[i] % p == 0) {
                qt[p]++;
            }
            while (a[i] % p == 0) {
                exp++;
                a[i] /= p;
            }
        }
    }

    for (const auto &p : primes) {
        if (qt[p] == n)
            continue;

        ans = min(ans, n - qt[p]);
    }

    if (ans == n)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}
