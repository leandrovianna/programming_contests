#include <bits/stdc++.h>
using namespace std;

const int M = 1000010;
bool notprime[M];
int fp[M]; // smallest first prime factor
vector<int> primes;

void sieve(int n) {
    assert(n < M);
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

int main() {
    int64_t b, ans = 1, f;

    sieve(M-1);

    cin >> b;

    for (const auto &p : primes) {
        if (b == 1) break;

        f = 0;

        while (b % p == 0) {
            f++;
            b /= p;
        }

        ans *= (f+1);
    }

    if (b > 1)
        ans *= 2;

    cout << ans << endl;
    return 0;
}
