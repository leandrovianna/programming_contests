// Codeforces - Ugly Pairs - 1156B Edu Round
#include <bits/stdc++.h>
using namespace std;

const int E = 26;
int cnt[E], sz;
bool vis[E];
string answer;

bool dfs(int e, int qtd) {
    vis[e] = true;

    if (qtd == sz) {
        return true;
    }

    for (int u = 0; u < E; u++) {
        if (abs(u - e) <= 1 || cnt[u] == 0) continue;

        if (!vis[u] && dfs(u, qtd + cnt[u])) {
            answer += string(cnt[u], 'a' + u);
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    string s;

    while (t--) {
        cin >> s;
        sz = s.size();

        memset(cnt, 0, sizeof(cnt));
        for (const auto &ch : s) {
            cnt[ch - 'a']++;
        }

        int start = -1;
        for (int e = 0; e < E; e++) {
            answer = "";
            memset(vis, false, sizeof(vis));
            if (dfs(e, cnt[e])) {
                answer += string(cnt[e], 'a' + e);
                start = e;
                break;
            }
        }

        if (start == -1) {
            cout << "No answer\n";
        } else {
            cout << answer << "\n";
        }
    }

    return 0;
}
