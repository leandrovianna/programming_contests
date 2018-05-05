//Codejam 2018 - Round 1C - A New Whole World
#include <bits/stdc++.h>
using namespace std;

const int N = 2010, L = 12;
set<char> mat[L];
set<string> words;
string ans;

bool gen(int i = 0, const int l = L) {
    if (i == l) {
        return words.count(ans) == 0;
    }

    for (const auto &c : mat[i]) {
        ans[i] = c;
        if (gen(i+1, l))
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int t, n, l;
    string str;

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        for (int i = 0; i < L; i++)
            mat[i].clear();
        words.clear();

        cin >> n >> l;

        for (int i = 0; i < n; i++) {
            cin >> str;
            words.insert(str);
            for (int j = 0; j < l; j++) {
                mat[j].insert(str[j]);
            }
        }

        ans = string(l, 'x');
        cout << "Case #" << ti << ": " << (gen(0, l) ? ans : "-") << "\n";
    }
    return 0;
}
