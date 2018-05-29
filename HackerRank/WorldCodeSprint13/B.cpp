// Hackerrank - World CodeSprint 13 - Group Formation
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100 * 1000 + 10;
    int n, m, a, b, f, s, t;
    string name, name1, name2;
    map<string, int> stud; // students
    map<string, int> gid;
    vector<string> group[N];

    cin >> n >> m >> a >> b >> f >> s >> t;

    for (int i = 0, g; i < n; i++) {
        cin >> name >> g;
        stud[name] = g;
        gid[name] = i;
        group[i].push_back(name);
    }

    for (int i = 0; i < m; i++) {
        cin >> name1 >> name2;
        int gid1 = gid[name1];
        int gid2 = gid[name2];

        if (gid1 != gid2) {
            int grades[4] = {0};

            int sz1 = group[gid1].size();
            for (const auto &nm : group[gid1]) {
               grades[stud[nm]]++; 
            }

            int sz2 = group[gid2].size();
            for (const auto &nm : group[gid2]) {
                grades[stud[nm]]++;
            }

            if (sz1 + sz2 <= b && grades[1] <= f
                    && grades[2] <= s && grades[3] <= t) {
                gid[name2] = gid1;
                group[gid1].insert(group[gid1].begin(), 
                        group[gid2].begin(), group[gid2].end());
                for (const auto &nm : group[gid1]) {
                    gid[nm] = gid1;
                }
            }
        }
    }

    set<string> ans;
    int max_size = 0;
    for (int i = 0; i < n; i++) {
        bool valid = gid[group[i][0]] == i;
        int sz = group[i].size();
        if (valid && a <= sz && sz <= b) {
            if (max_size <= sz) {
                if (max_size != sz)
                    ans.clear();
                max_size = sz;
                ans.insert(group[i].begin(), group[i].end()); 
            }
        }
    }

    if (ans.size() == 0)
        cout << "no groups\n";

    for (const auto &nm : ans) {
        cout << nm << "\n";
    }

    return 0;
}
