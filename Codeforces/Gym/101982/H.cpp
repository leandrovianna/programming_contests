#include <bits/stdc++.h>
using namespace std;

const int M = 1000100;
bool notprime[M];
vector<int> primes;
unordered_set<int> exist;

void sieve() {
    for (int i = 2; i < M; i++) {
        if (notprime[i] == false) {
            for (int j = i+i; j < M; j += i) {
                notprime[j] = true;
            }
            primes.push_back(i);
            exist.insert(i);
        }
    }
}

int main() {
    int x;
    cin >> x;

    sieve();

    int ans = 0;

    while (x >= 4) {
        for (size_t i = 0; i < primes.size(); i++) {
            if (exist.count(x - primes[i])) {
                x = (x - primes[i]) - primes[i];
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
