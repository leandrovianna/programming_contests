// Codeforces - Array K-Coloring - 1102B Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
vector<int> bucket[N];
int color[N];

int main() {
    int n, k;

    cin >> n >> k;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        bucket[x].push_back(i);
    }

    bool valid = true;
    int last_color = -1;

    for (int x = 1; x <= 5000; x++) {
        if ((int) bucket[x].size() > k) {
            valid = false;
            break;
        }

        int c = (last_color+1)%k;

        for (const auto &p : bucket[x]) {
            color[p] = c;
            last_color = c;
            c++;
            c %= k;
        }
    }

    if (valid) {
        set<int> ss;
        for (int i = 0; i < k; i++)
            ss.insert(i);

        for (int i = 0; i < n; i++) {
            ss.erase(color[i]);
        }

        if (ss.size() > 0) {
            valid = false;
        }
    }

    if (!valid) {
        cout << "NO" << endl;
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << color[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
