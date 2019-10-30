#include <bits/stdc++.h>
using namespace std;

const int N = 600100, E = 10;
int trie[N][E], cnt = 1;

string ans;

bool ismin(string &x, string &y) {
    if (x.size() < y.size())
        return true;
    else
        return x < y;
}

string s;
void dfs(int idx) {
    for (int e = 0; e < E; e++) {
        s += static_cast<char>(e + '0');

        if (trie[idx][e] == -1) {
            if (ismin(s, ans)) {
                ans = s;
            }
        } else {
            dfs(trie[idx][e]);
        }

        s.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;

        memset(trie, -1, sizeof(trie));
        cnt = 1;

        for (int i = 0; i < n; i++) {
            int idx = 0;
            for (int j = i; j < min(n, i+6); j++) {
                int x = s[j] - '0';
                if (trie[idx][x] == -1) {
                    trie[idx][x] = cnt;
                    cnt++;
                }

                idx = trie[idx][x];
            }
        }

        s = "";
        ans = "9999999";
        dfs(0);

        cout << ans.size() << " " << ans << "\n";
    }
    return 0;
}
