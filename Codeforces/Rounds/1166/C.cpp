// Codeforces - A Tale of Two Lands - 1166C Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N];

bool test(int i, int j) {
    int e1 = abs(a[i] - a[j]),
        e2 = abs(a[i] + a[j]);

    return (e1 <= abs(a[i]) && abs(a[j]) <= e2)
        || (e2 <= abs(a[i]) && abs(a[j]) <= e1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n, [](const auto &a, const auto &b) {
            return abs(a) < abs(b);
            });

    int64_t answer = 0;
    for (int i = 0; i < n; i++) {
        int lo = i+1, hi = n-1, mid;
        int j = i;
        while (lo <= hi) {
            mid = (lo + hi) / 2;

            if (test(i, mid)) {
                j = max(j, mid);
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        answer += j - i;
    }

    cout << answer << "\n";
    return 0;
}
