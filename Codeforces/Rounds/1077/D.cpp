#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
int n, k, a[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    const int M = 2 * 100 * 1000;
    int low = 1, high = M, mid;
    int ans = 0;
    vector<int> vec_ans;

    while (low <= high) {
        mid = (low + high) / 2;

        int v = 0;
        for (int i = 1; i <= M; i++) {
            v += cnt[i] / mid;
        }

        if (v >= k) {
            if (ans < mid) {
                ans = mid;
                vec_ans.clear();
                for (int i = 1; i <= M; i++) {
                    for (int j = 0, t = cnt[i] / mid; j < t; j++) { 
                        vec_ans.push_back(i);
                        if ((int) vec_ans.size() == k)
                            break;
                    }
                    if ((int) vec_ans.size() == k)
                        break;
                }
            }

            low = mid+1;
        } else if (v < k) {
            high = mid-1;
        }
    }

    for (const auto &x : vec_ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
