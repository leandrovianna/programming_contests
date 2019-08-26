// Codeforces - Trailing Loves - 1114C Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, b;

    cin >> n >> b;

    vector<int64_t> primes, exp;

    int64_t i = 2;
    while (i * i <= b) {
        if (b % i == 0) {
            primes.push_back(i);
            int cnt = 0;
            while (b % i == 0) {
                b /= i;
                cnt++;
            }
            exp.push_back(cnt); 
        }

        i++;
    }

    if (b > 1) {
        primes.push_back(b);
        exp.push_back(1);
    }

    int64_t r = numeric_limits<int64_t>::max();

    for (size_t i = 0; i < primes.size(); i++) {
        int64_t m = n, cnt = 0;
        while (m > 0) {
            cnt += m / primes[i];
            m /= primes[i];
        }

        r = min(r, cnt / exp[i]);
    }

    cout << r << "\n";
    return 0;
}
