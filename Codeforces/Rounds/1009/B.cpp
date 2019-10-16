// Codeforces - Minimum Ternary String - 1009B Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            a[k++] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != '1')
            a[k++] = s[i] - '0';
    }

    a[n] = 2;
    for (int i = 0, cnt0 = 0, cnt1 = 0; i <= n; i++) {
        if (a[i] == 0) cnt0++;
        else if (a[i] == 1) cnt1++;
        else if (a[i] == 2) {
            int j = i-1;

            while (cnt0 > 0 || cnt1 > 0) {
                assert(j >= 0);
                if (cnt1 > 0) {
                    a[j] = 1;
                    cnt1--;
                } else if (cnt0 > 0) {
                    a[j] = 0;
                    cnt0--;
                }
                j--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
