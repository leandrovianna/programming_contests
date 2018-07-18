// Codeforces - Alphabetic Removals - 999C Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    const int N = 30;
    set<int> cnt[N];
    string s;
    
    cin >> n >> k >> s;
    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        cnt[c-'a'].insert(i);
    }

    for (int i = 0; i < k; i++) {
        for (int x = 0; x < N; x++) {
            if (cnt[x].size() > 0) {
                auto it = cnt[x].begin();
                s[*it] = 'X';
                cnt[x].erase(it);
                break;
            }
        }
    }

    for (const auto &c : s) {
        if (c != 'X')
            cout << c;
    }

    cout << endl;

    return 0;
}
