// Codeforces - Remove Duplicates - 978B Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100;
    int n, c;
    int a[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            if (a[i] == a[j]) {
                a[j] = -1;
            }
        }
    }

    c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1)
            c++;
    }

    cout << c << "\n";
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            cout << a[i];

            if (i < n-1)
                cout << " ";
            else
                cout << "\n";
        }
    }

    return 0;
}
