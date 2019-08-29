// Codeforces - Nauuo and Chess - 1173B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<pair<int, int>> ans;

    int order = 0;
    bool flag = true;
    for (int k = 0, i = 1, j = 1; k < n; k++) {
        ans.push_back({i, j});

        order = max({order, i, j});

        if (flag) j++;
        else i++;
        flag = !flag;
    }

    cout << order << "\n";
    for (const auto &p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
