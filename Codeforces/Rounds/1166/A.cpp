// Codeforces - Silent Classroom - 1166A Div2
#include <bits/stdc++.h>
using namespace std;

const int E = 30;
int cnt[E];

int main() {
    string s;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cnt[s[0] - 'a']++;
    }

    int x = 0;

    for (int e = 0; e < E; e++) {
        int y = cnt[e] / 2;
        int z = (cnt[e] + 1) / 2;
        x += (y * (y - 1)) / 2;
        x += (z * (z - 1)) / 2;
    }

    cout << x << "\n";
    return 0;
}
