// UVA - Team Queue - 540
#include <bits/stdc++.h>
using namespace std;

const int T = 1010;
map<int, int> teamOf;
queue<int> teams, team[T];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k = 1;
    while (cin >> t && t) {
        teamOf.clear();
        while (!teams.empty()) {
            teams.pop();
        }

        for (int i = 0, n; i < t; i++) {
            cin >> n;
            while (!team[i].empty()) {
                team[i].pop();
            }
            for (int j = 0, x; j < n; j++) {
                cin >> x;
                teamOf[x] = i;
            }
        }

        cout << "Scenario #" << k << "\n";

        string cmd;
        int x;
        while (cin >> cmd && cmd != "STOP") {
            if (cmd == "ENQUEUE") {
                cin >> x;

                if (team[teamOf[x]].empty()) {
                    teams.push(teamOf[x]);
                }

                team[teamOf[x]].push(x);
            } else if (cmd == "DEQUEUE") {
                int y = teams.front();
                cout << team[y].front() << "\n";
                team[y].pop();

                if (team[y].empty()) {
                    teams.pop();
                }
            }
        }

        cout << "\n";
        k++;
    }
    return 0;
}
