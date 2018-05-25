// Codeforces - Easter Eggs - 78B Div2
#include <bits/stdc++.h>
using namespace std;

char get(int x) {
    switch (x) {
        case 0:
            return 'R';
        case 1:
            return 'O';
        case 2:
            return 'Y';
        case 3:
            return 'G';
        case 4:
            return 'B';
        case 5:
            return 'I';
        case 6:
            return 'V';
    }

    return 'X';
}

int mod(int a, int m) {
    if (a < 0)
        return m + a;
    else
        return a % m;
}

int main() {
    int n;
    const int C = 7;
    int a[110] = {0};

    cin >> n;

    int opt[C+1], minimum = 0;
    for (int i = 0; i < n; i++) a[i] = C;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < C; j++) {
            opt[j] = 1;
        }

        for (int j = 1; j <= 3; j++) {
            opt[a[mod(i-j, n)]] = 0;
            opt[a[mod(i+j, n)]] = 0;
        }


        for (int j = (minimum < C ? minimum : 0); j < C; j++) {
            if (opt[j] == 1) {
                a[i] = j;
                if (minimum < C)
                    minimum = j+1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int j = (i+1) % n, k = (i+2) % n,
            h = (i+3) % n;
        if (a[i] == a[j] || a[i] == a[k] || a[i] == a[h]
                || a[j] == a[k] || a[j] == a[h]
                || a[k] == a[h]) {
            cout << "deu merda pos " << i << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << get(a[i]);
    }
    cout << endl;
    return 0;
}
