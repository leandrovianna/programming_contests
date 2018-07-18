// Spoj - SUBSUMS - Subset Sums
#include <bits/stdc++.h>
using namespace std;

vector<int> generate_subsets(int nums[], int beg, int en) {
    vector<int> sums;
    for (int mask = 0; mask < (1 << (en - beg)); mask++) {
        int sum = 0;
        for (int i = 0; i < (en - beg); i++) {
            if (mask & (1 << i)) {
                sum += nums[beg + i];
            }
        }
        sums.push_back(sum);
    }

    return sums;
}

int main() {
    const int N = 40;
    int n, a, b, v[N];

    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> s1, s2;

    s1 = generate_subsets(v, 0, n/2);
    s2 = generate_subsets(v, n/2, n);

    sort(s2.begin(), s2.end());

    int64_t ans = 0;

    for (const auto &x : s1) {
        auto it1 = lower_bound(s2.begin(), s2.end(), a - x);
        auto it2 = upper_bound(s2.begin(), s2.end(), b - x);

        ans += distance(it1, it2);
    }

    cout << ans << endl;

    return 0;
}
