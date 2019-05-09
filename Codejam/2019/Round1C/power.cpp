#include <bits/stdc++.h>
using namespace std;

const int E = 5;
vector<int> freq[E];
bool vis[E];

int main() {
    int t, f;

    cin >> t >> f;

    for (int ti = 1; ti <= t; ti++) {
        char ch;
        vector<int> indexes;
        for (int i = 1; i <= 119; i++) {
            indexes.push_back(i * 5);
        }
        string answer = "";

        for (int i = 0; i < E; i++) {
            vis[i] = false;
        }

        for (int j = 5; j > 1; j--) {
            for (int i = 0; i < E; i++) {
                freq[i].clear();
            }

            for (const auto &idx : indexes) {
                cout << idx << endl;
                cin >> ch;
                if (ch == 'N')
                    return 0;

                freq[ch - 'A'].push_back(idx);
            }

            int v = indexes.size() + 1;
            v /= j;
            v--;

            for (int i = 0; i < E; i++) {
                if (!vis[i] && (int) freq[i].size() == v) {
                    indexes.clear();
                    vis[i] = true;
                    answer += 'A' + i;
                    for (const auto &idx : freq[i]) {
                        indexes.push_back(idx-1);
                    }
                    break;
                }
            }
        }

        for (int i = 0; i < E; i++) {
            if (!vis[i]) {
                answer += 'A' + i;
                break;
            }
        }

        reverse(answer.begin(), answer.end());

        cout << answer << endl;
        cin >> ch;
        if (ch == 'N')
            return 0;
    }
    return 0;
}
