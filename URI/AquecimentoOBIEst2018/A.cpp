#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n;

    while (n--) {
        vector<int> a;
        cin >> m;
        for (int i = 0, x; i < m; i++) {
            cin >> x;
            if (x & 1)
                a.push_back(x);
        }

        sort(a.begin(), a.end());

        if (a.size() == 0) {
            cout << "\n";
            continue;
        }

        vector<int> b;
        for (size_t i = 0, j = a.size()-1; i < j; i++, j--) {
            b.push_back(a[j]);
            b.push_back(a[i]);
        }

        if (a.size() & 1)
            b.push_back(a[a.size()/2]);

        for (size_t i = 0; i < b.size(); i++) {
            cout << b[i];
            if (i != b.size()-1)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
