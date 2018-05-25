#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1010;
    int n, a[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int mid = (n % 2 ? n / 2 : n / 2 - 1);
    cout << a[mid] << endl;
    return 0;
}
