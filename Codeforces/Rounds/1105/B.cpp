// Codeforces - Zuhair and Strings - 1105B
#include <bits/stdc++.h>
using namespace std;

const int E = 30;
vector<int> cnt[E];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    char ch, prev;

    cin >> n >> k;

    int qtd = 0;
    for (int i = 0; i < n; i++) {
        cin >> ch;

        if (i == 0 || ch == prev) {
            qtd++;
        } else {
            cnt[prev - 'a'].push_back(qtd);
            qtd = 1;
        }

        prev = ch;
    }

    cnt[ch - 'a'].push_back(qtd);

    int answer = 0;

    for (int e = 0; e < E; e++) {
        int lanswer = 0;
        for (const auto &sz : cnt[e]) {
            lanswer += sz / k;
        }

        answer = max(answer, lanswer);
    }

    cout << answer << "\n";
    return 0;
}
