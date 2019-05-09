#include <bits/stdc++.h>
using namespace std;

const int A = 300;
string plays[A];
bool mark[A];
int pos[A];
const string play = "RPS";

int main() {
    int t, a;

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> a;
        for (int i = 0; i < a; i++) {
            cin >> plays[i];
            mark[i] = false;
            pos[i] = 0;
        }

        string answer = "";
        int cnt = 0;
        while (cnt < a) {
            int sz = answer.size();
            if (sz > 500) {
                answer = "IMPOSSIBLE";
                break;
            }

            int maxwins = 0, maxj = -1;
            for (int j = 0; j < 3; j++) {
                int wins = 0;
                for (int i = 0; i < a; i++) {
                    if (mark[i]) continue;

                    char p = play[j], q = plays[i][pos[i]];
                    if ((p == 'R' && q == 'S')
                            || (p == 'S' && q == 'P')
                            || (p == 'P' && q == 'R')) {
                        wins++;
                    } else if (p != q) {
                        wins = -1;
                        break;
                    }
                }

                if (maxwins < wins) {
                    maxj = j;
                    maxwins = wins;
                }
            }

            if (maxj != -1) {
                answer += play[maxj];
                for (int i = 0; i < a; i++) {
                    if (mark[i]) continue;

                    char p = play[maxj], q = plays[i][pos[i]];
                    if ((p == 'R' && q == 'S')
                            || (p == 'S' && q == 'P')
                            || (p == 'P' && q == 'R')) {
                        mark[i] = true;
                        cnt++;
                    } else {
                        // p == q
                        pos[i]++;
                        pos[i] %= plays[i].size();
                    }
                }
            } else {
                answer = "IMPOSSIBLE";
                break;
            }
        }

        cout << "Case #" << ti << ": " << answer << "\n";
    }
    return 0;
}
