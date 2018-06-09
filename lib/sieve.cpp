#include <bits/stdc++.h>
using namespace std;

const int M = 10000010;
bool notprime[M];
void sieve(vector<int> &primes, int n) {
    assert(n < M);
    notprime[0] = notprime[1] = true;
    for (int64_t i = 2; i <= n; i++) {
        if (!notprime[i]) {
            primes.push_back(i);
            for (int64_t j = i * i; j <= n; j += i) {
                notprime[j] = true;
            }
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
    int n;
    vector<int> p;

    cin >> n;

    sieve(p, n);

    return 0;
}
