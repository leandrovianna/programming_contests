// Codeforces - Competitive Programmer
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;

    cin >> n;

    while (n--) {
        int sum = 0;
        bool hasZero = false, hasEven = false;

        cin >> s;
        for (const auto &ch : s) {
            int d = ch - '0';
            sum += d;

            if (!hasZero && d == 0)
                hasZero = true;
            else if (!hasEven && d % 2 == 0)
                hasEven = true;
        }

        if (hasZero && hasEven && sum % 3 == 0)
            cout << "red\n";
        else
            cout << "cyan\n";
    }
    return 0;
}
