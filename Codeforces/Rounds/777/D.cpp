// Codeforces - Cloud of Hashtags - 777D Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 500100;
string str[N];
int pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
        pos[i] = str[i].size();
    }

    for (int i = n-2; i >= 0; i--) {
        for (int j = 0, sz = pos[i]; j < sz; j++) {
            if (j >= pos[i+1] || str[i][j] > str[i+1][j]) {
                pos[i] = j;
                break;
            } else if (str[i][j] < str[i+1][j]) {
                break;
            }
        }

    }

    for (int i = 0; i < n; i++) {
        cout << str[i].substr(0, pos[i]) << "\n";
    }
    return 0;
}
