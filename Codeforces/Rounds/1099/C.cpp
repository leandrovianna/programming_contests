// Codeforces - Postcard - 1099C
#include <bits/stdc++.h>
using namespace std;

const int N = 210;
int repeat[N];

int main() {
    string s;
    int k;

    cin >> s >> k;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        repeat[i] = 1;
    }

    int m = 0;
    for (const auto &ch : s) {
        if (ch != '?' && ch != '*')
            m++;
    }

    int p1 = 0;
    while (m > k) {
        while (p1 < n && s[p1] != '?' && s[p1] != '*') {
            p1++;
        }

        if (p1 == n) {
            cout << "Impossible" << endl;
            return 0;
        }

        s[p1-1] = '@'; // remove the previous letter
        m--;
        p1++;
    }

    if (m < k) {
        p1 = 0;
        while (p1 < n && s[p1] != '*') {
            p1++;
        }

        if (p1 == n) {
            cout << "Impossible" << endl;
            return 0;
        }

        repeat[p1-1] = k - m + 1;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != '?' && s[i] != '*' && s[i] != '@') {
            for (int j = 0; j < repeat[i]; j++) {
                cout << s[i];
            }
        }
    }

    cout << endl;
    return 0;
}
