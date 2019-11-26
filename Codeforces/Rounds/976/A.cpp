// Codeforces - Minimum Binary Number - 976A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 0;
    char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        if (ch == '0')
            cnt++;
    }

    if (cnt == n)
        cout << "0\n";
    else
        cout << "1" << string(cnt, '0') << "\n";
    return 0;
}
