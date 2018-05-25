//Codechef - Weight of Numbers - April Challenge 2018
#include <bits/stdc++.h>
using namespace std;

int64_t power(int64_t b, int64_t e, int64_t mod) {
    int64_t ans = 1;
    while (e) {
        if (e & 1) {
           ans = (ans * b) % mod;
        }

        b = (b * b) % mod;
        e >>= 1;
    }

    return ans;
}

int main() {
    // 10^9 + 7
    const int64_t mod = 1000000007;
    int64_t n;
    int t, w;

    cin >> t;
    while (t--) {
       cin >> n >> w; 

       int c = 0;
       for (int i = 1; i <= 9; i++) {
           for (int j = 0; j <= 9; j++) {
               if (j - i == w)
                   c++;
           }
       }

       int64_t ans = (c * power(10, n - 2, mod)) % mod;
       cout << ans << endl;
    }

    return 0;
}
