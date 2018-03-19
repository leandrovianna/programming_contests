//Codeforces - Sum of Digits - 102B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    int sum = 10, cc = 0;

    if (s.size() > 1) {
        sum = 0;
        for (size_t i = 0; i < s.size(); i++) {
            sum += s[i] - '0';
        }
        cc++;

        while (sum > 9) {
            int x = sum;
            sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            cc++;
        }
    }

    cout << cc << endl;
    return 0;
}
