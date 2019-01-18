#include <bits/stdc++.h>
using namespace std;

const int N = 210;
string a[N];
int ans[N];

bool solve(string pf, string sf, int z) {
    //cout << pf << " " << sf << endl;
    for (int i = 0; i < z; i++) {
        ans[i] = 0;
    }

    for (int i = 0; i < z; i++) {
        if (a[i] == pf) {
            ans[i] = 1;
            break;
        }
    }

    for (int i = 0; i < z; i++) {
        if (ans[i] == 0 && a[i] == sf) {
            ans[i] = 2;
            break;
        }
    }

    for (int t = 0, i, sz = pf.size(); t < sz-1; t++) {
        pf.pop_back();

        for (i = 0; i < z; i++) {
            if (ans[i] == 0 && a[i] == pf) {
                ans[i] = 1;
                break;
            }
        }

        // not found eq.
        if (i == z) {
            return false;
        }
    }

    for (int t = 0, i, sz = sf.size(); t < sz-1; t++) {
        sf = sf.substr(1);

        for (i = 0; i < z; i++) {
            if (ans[i] == 0 && a[i] == sf) {
                ans[i] = 2;
                break;
            }
        }

        // not found eq.
        if (i == z) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, s1 = "", s2 = "";
    int n, z;
    cin >> n;
    z = 2 * n - 2;

    for (int i = 0; i < z; i++) {
        cin >> s;
        if ((int) s.size() == n-1) {
            if (s1 == "")
                s1 = s;
            else
                s2 = s;
        }

        a[i] = s;
    }

    if (!solve(s1, s2, z)) {
        solve(s2, s1, z);
    }

    for (int i = 0; i < z; i++) {
        //cout << a[i] << " ";
        cout << (ans[i] == 1 ? "P" : "S");
        //cout << "\n";
    }
    cout << "\n";

    return 0;
}
