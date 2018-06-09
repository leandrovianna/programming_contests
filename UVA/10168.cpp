// UVA - Summation of Four Primes - 10168
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

int main() {
    const int N = 10000000;
    int n;
    vector<int> p;
    
    sieve(p, N);

    int a = 2, b;
    while (cin >> n) {
        if (n < 8) {
            cout << "Impossible.\n";
            continue;
        }

        if (n & 1) {
            b = 3;
        } else {
            b = 2;
        }

        n -= a + b;

        for (const auto &x : p) {
            if (n-x >= 0 && !notprime[n-x]) {
                cout << a << " " << b << " " << x << " "
                    << n-x << "\n";
                break;
            }
        }
    }
    return 0;
}
