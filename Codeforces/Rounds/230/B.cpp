// Codeforces - T-primes - 230B Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 * 1000 * 10 + 10;
bool notprime[N];
vector<int> primes;
void sieve(int n) {
    assert(n < N);
    notprime[0] = notprime[1] = true;

    for (int i = 2; i <= n; i++) {
        if (!notprime[i]) {
            for (int j = i+i; j <= n; j += i) {
                notprime[j] = true;
            }
            primes.push_back(i);
        }
    }
}

bool isTPrime(int64_t x) {
    int lo = 2, hi = N-1;
    int64_t y; 

    while (lo <= hi) {
        y = (lo + hi) / 2;

        if (y * y == x) {
            return !notprime[y];
        } else if (y * y < x) {
            lo = y+1;
        } else {
            hi = y-1;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int64_t x;
    cin >> n;

    sieve(N-1);

    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << (isTPrime(x) ? "YES" : "NO") << "\n";
    }

    return 0;
}
