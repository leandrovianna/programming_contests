#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    const int N = 1010;
    int n, ans[N];
    cin >> s;
    n = s.size();

    for (int i = 0; i < n-1; i++) {
        if (s[i] != s[i+1]) {
            ans[i] = 1;
        } else {
            ans[i] = 0;
        }
    }

    ans[n-1] = (s[n-1] == 'a' ? 1 : 0);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
