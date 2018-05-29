// Codeforces - Fence - 363B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 2 * 100 * 1000 + 10;
    int n, k;
    int a[N];

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int minsum, ans, sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    
    minsum = sum;
    ans = 0;

    for (int i = 1; i < n-k+1; i++) {
        sum -= a[i-1];
        sum += a[i+k-1];
        if (sum < minsum) {
            ans = i;
            minsum = sum;
        }
    }
    
    cout << 1+ans << endl;
    return 0;
}
