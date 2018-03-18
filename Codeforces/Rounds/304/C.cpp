//Codeforces - Lucky Permutation Triple - 304C Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    if (n % 2 == 0)
        return cout << "-1" << endl, 0;

    for (int x = 0; x < 2; x++) {
        for (int i = 0; i < n; i++) {
            cout << i;
            if (i < n-1)
                cout << " ";
            else
                cout << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (2 * i) % n;
        if (i < n-1)
            cout << " ";
        else
            cout << endl;
    }

    return 0;
}
