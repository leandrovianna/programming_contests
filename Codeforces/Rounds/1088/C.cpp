// Codeforces - Ehab and a 2-operation task - 1088C
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MXVALUE = 100000; // 10**5
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << n + 1 << "\n";
    cout << "1 " << n << " " << MXVALUE << "\n";

    for (int i = 0; i < n; i++) {
        cout << "2 " << i+1 << " " << a[i] + MXVALUE - i << "\n";
    }
    return 0;
}
