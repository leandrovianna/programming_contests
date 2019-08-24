// Codeforces - Lunar New Year and Number Division - 1106C
#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
int64_t a[N];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int64_t answer = 0;

    for (int i = 0; i < n/2; i++) {
        answer += (a[i] + a[n-1-i]) * (a[i] + a[n-1-i]);
    }

    cout << answer << "\n";

    return 0;
}
