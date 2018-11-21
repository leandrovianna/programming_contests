// Codeforces - Maximum Sum of Digits - 1060B Div1+Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;

    int ans = 0, carry = 0, d;
    while (n) {
        d = n % 10;
        if (carry == 1 || d != 9) {
            ans += 10 + d - carry;
            carry = 1;
        } else {
            ans += d - carry;
            carry = 0;
        }

        n /= 10;
    }

    if (carry)
        ans -= 10;

    cout << ans << endl;
    return 0;
}
