// UVA Online Judge - The jackpot - 10684
#include <bits/stdc++.h>
using namespace std;

int64_t kadane(int64_t a[], const int n) {
    int64_t sum = 0, ans = a[0];
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

int main() {
    const int N = 10010;
    int n;
    int64_t a[N];

    while (cin >> n, n > 0) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int64_t max_value = kadane(a, n);

        if (max_value <= 0) {
            cout << "Losing streak." << endl;
        } else {
            cout << "The maximum winning streak is " << max_value
                << "." << endl;
        }
    }
    return 0;
}
