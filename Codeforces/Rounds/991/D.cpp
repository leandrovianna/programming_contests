// Codeforces - Bishwock - 991D Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 2;
    string grid[N];

    cin >> grid[0] >> grid[1];

    int ans = 0;

    for (int i = 0; i + 1 < (int) grid[0].size(); i++) {
        char &ul = grid[0][i];
        char &ur = grid[0][i+1];
        char &dl = grid[1][i];
        char &dr = grid[1][i+1];

        if (ul == '0' && ur == '0' && dl == '0') {
            ul = 'X';
            ur = 'X';
            dl = 'X';
            ans++;
        } else if (ur == '0' && dl == '0' && dr == '0') {
            ur = 'X';
            dl = 'X';
            dr = 'X';
            ans++;
        } else if (ul == '0' && dl == '0' && dr == '0') {
            ul = 'X';
            dl = 'X';
            dr = 'X';
            ans++;
        } else if (ul == '0' && ur == '0' && dr == '0') {
            ul = 'X';
            ur = 'X';
            dr = 'X';
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
