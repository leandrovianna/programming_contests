// UVA - Twin Primes - 10394
#include <bits/stdc++.h>
using namespace std;

const int N = 20 * 1000 * 1000 + 10;
bool notprime[N];
void sieve(vector<int> &primes, int64_t n) {
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
    int s;
    vector<int> p;

    sieve(p, N-1);

    vector<pair<int, int> > twin;
    for (size_t i = 1; i < p.size(); i++) {
        if (p[i] - 2 == p[i-1]) {
            twin.push_back({p[i-1], p[i]});
        }
    }

    while (cin >> s) {
        s--; 
        cout << "(" << twin[s].first
            << ", " << twin[s].second
            << ")\n";
    }
}
