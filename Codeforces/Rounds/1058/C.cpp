// Codeforces - Vasya and Golden Ticket - 1058C Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int n;
    int pref[N];
    string s;

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        pref[i] = (i == 0 ? 0 : pref[i-1]) + (s[i] - '0');
    }

    bool ans = false;
    int target;
    for (int i = 0; i < n-1; i++) {
        target = pref[i] * 2;
        for (int j = i+1; j < n-1; j++) {
            if (pref[j] == target && pref[j] != pref[j+1]) {
                target += pref[i];
            }
        }

        if (pref[n-1] == target) {
            ans = true;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}
