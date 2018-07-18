#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int n, q;
    pair<int, int> arr[N];

    cin >> n >> q;
    for (int i = 0, x; i < n; i++) {
        cin >> arr[i].first >> x;
        arr[i].second = x - arr[i].first;
    }

    int bud = q;
    for (int i = 0; i < 12; i++) {
        auto it = upper_bound(arr, arr+n, {bud, 0});
        if (it != arr+n)
            cout << it->first << endl;
    }

    cout << bud << endl;

    return 0;
}
