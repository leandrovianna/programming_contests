// LIS algorithm with function to print the sequence
// UVA - What Goes Up - 481
#include <bits/stdc++.h>
using namespace std;

namespace LIS {
    const int N = 100 * 1000 + 10;
    int parent[N], l[N], l_id[N], l_end;
    void lis(int a[], const int n) {
        l_end = 0;
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(l, l+l_end, a[i]) - l;

            l[pos] = a[i];
            l_id[pos] = i;
            parent[i] = pos ? l_id[pos-1] : -1;

            if (pos == l_end) {
                l_end++;
            }
        }
    }

    vector<int> get_lis(int a[]) {
        stack<int> st;
        for (int x = l_id[l_end-1]; x != -1; x = parent[x]) {
            st.push(a[x]);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
}

int main() {
    const int N = 100 * 1000 + 10;
    int x, n = 0;
    int a[N];
    
    while (cin >> x) {
        a[n++] = x;
    }

    LIS::lis(a, n);

    vector<int> ans = LIS::get_lis(a);
    cout << ans.size() << "\n-\n";
    for (const auto &x : ans) {
        cout << x << "\n";
    }

    return 0;
}
