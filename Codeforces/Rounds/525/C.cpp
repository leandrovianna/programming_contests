#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
int64_t arr[N];

int main() {
    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n, greater<>());

    vector<int64_t> doubles;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1] || arr[i] == arr[i-1] - 1) {
            //cout << i << ", " << i - 1 << endl;
            doubles.push_back(arr[i]);
            i++;
        }
    }

    int64_t ans = 0;
    for (size_t i = 1; i < doubles.size(); i += 2) {
        ans += doubles[i] * doubles[i-1];
    }

    cout << ans << endl;

    return 0;
}
