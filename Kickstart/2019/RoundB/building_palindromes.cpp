// Kickstart 2019 - Round B - Building Palindromes
#include <bits/stdc++.h>
using namespace std;

const int N = 100100, E = 30;
int pref[N][E];

void sum_into(int p1[], const int p2[], int signal = 1) {
    for (int e = 0; e < E; e++) {
        p1[e] += p2[e] * signal;
    }
}

bool test(int l, int r) {
    l--;
    r--;

    int p[E];

    for (int e = 0; e < E; e++) {
        p[e] = 0;
    }

    sum_into(p, pref[r]);
    if (l > 0) {
        sum_into(p, pref[l-1], -1);
    }

    int cntOdd = 0;
    for (int e = 0; e < E; e++) {
        if (p[e] & 1)
            cntOdd++;
    }

    return cntOdd <= 1;
}

int main() {
    int t, q, n;
    string s;

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> n >> q;
        cin >> s;

        for (int i = 0; i < n; i++) {
            for (int e = 0; e < E; e++) {
                pref[i][e] = 0;
            }

            pref[i][s[i] - 'A']++;
            if (i > 0)
                sum_into(pref[i], pref[i-1]);

            /*
            cout << "i: " << i << endl;
            for (int e = 0; e < E; e++) {
                cout << e << ": " << pref[i][e] << endl;
            }
            */
        }

        int answer = 0;
        for (int i = 0, l, r; i < q; i++) {
            cin >> l >> r;
            if (test(l, r)) {
                answer++;
            }
        }

        cout << "Case #" << ti << ": " << answer << "\n";
    }
    return 0;
}
