// Codeforces - Great Guest Gathering - 101137G - NEERC Moscow Subregional 2016
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
set<int> plates[N];
int cnt[N];

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cnt[i] = n;
    }

    cout << "1 1 0\n"; // pizza 1 to 0, type 1
    cnt[1]--;

    bool done = false;

    while (!done) {
        for (int i = 1; i <= n; i++) {
            if (cnt[i] + static_cast<int>(plates[i].size()) == n-1) {
                for (int j = n; j >= 1; j--) {
                    if (j == i) continue;
                    if (plates[i].count(j) == 0) {
                        cnt[j]--;
                        plates[i].insert(j);
                        cout << j << " " << j << " " << i << "\n";
                        break;
                    }
                }

                break;
            }
        }

        done = true;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 1) {
                done = false;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] + static_cast<int>(plates[i].size()) == n-1) {
            cout << "0 1 " << i << "\n";
            break;
        }
    }
    return 0;
}
