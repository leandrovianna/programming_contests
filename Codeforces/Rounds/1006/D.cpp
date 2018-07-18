#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a, b;

    cin >> n;
    cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && b[i] != a[n-i-1] && b[i] != b[n-i-1]) {
           ans++; 
        }
    }

    cout << ans << endl;
    return 0;
}
