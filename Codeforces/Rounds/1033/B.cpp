#include <bits/stdc++.h>
using namespace std;

const int M = 10000010;
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

bool isPrime(vector<int> &primes, int64_t n) {
    if (n < M) return !notprime[n];

    for (const auto &p : primes) {
        if (n % p == 0)
            return false;
    }

    return true;
}

int main() {
    int t;
    int64_t a, b;

    sieve(M-1);
    cin >> t;

    while (t--) {
        cin >> a >> b;
        if (a-1 == b && isPrime(primes, 2*b+1)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
