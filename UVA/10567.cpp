// UVA - Helping Fill Bates - 10567
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, vector<int> > mp;
    string str;
    int q;
    bool found;

    cin >> str >> q;
    
    int k = 0, st, en;

    for (const auto &c : str) {
        mp[c].push_back(k);
        k++;
    }

    for (int i = 0; i < q; i++) {
        cin >> str;

        found = true;
        k = 0;
        st = -1;
        en = -1;
        for (const auto &c : str) {
            //cout << "try to find " << c << " from pos. " << k << endl;
            auto it = lower_bound(mp[c].begin(), mp[c].end(), k);

            if (it == mp[c].end()) {
                //cout << "do not find" << endl;
                found = false;
                break;
            } else {
                if (st == -1)
                    st = *it;

                en = *it;
                k = *it + 1;
            }
        }

        if (found)
            cout << "Matched " << st << " " << en << endl;
        else
            cout << "Not matched" << endl;
    }

    return 0;
}
