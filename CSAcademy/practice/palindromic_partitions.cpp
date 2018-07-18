// CS Academy - Palindromic Partitions
#include <bits/stdc++.h>
using namespace std;

const uint64_t MOD = 1000 * 1000 * 1000 + 7;
const uint64_t D = 33;

int main() {
    int t;
    string s;

    cin >> t;
    while (t--) {
        cin >> s;

        uint64_t left = 0, right = 0;
        int ans = 0, exp = 0;
        int n = s.size();
        for (int i = 0; i < n/2; i++) {
            left = (left + (s[i] - 'a') * (int)pow(D, exp)) % MOD;
            right = (right * D + (s[n-1-i] - 'a')) % MOD;
            exp++;

            if (left == right) {
                ans += 2;
                left = right = 0;
                exp = 0;
            }
        }

        if (n % 2)
            ans++;
        else if (left != right) {
            ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}
