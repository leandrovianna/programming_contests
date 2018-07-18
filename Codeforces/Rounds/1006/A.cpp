#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const int N = 1010;
    int n;
    int64_t a[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            a[i]--;
        }
        
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
