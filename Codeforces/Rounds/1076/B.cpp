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

int main() {
    int64_t n;

    sieve(M-1);

    cin >> n;

    if (n % 2 == 0)
        cout << n / 2 << endl;
    else {
        bool found = false;
        for (const auto &p : primes) {
            if (n % p == 0) {
                cout << 1 + (n-p) / 2 << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << 1 << endl;
        }
    }

    return 0;
}
