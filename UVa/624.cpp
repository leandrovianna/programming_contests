// UVa Online Judge - 624 - CD
#include <bits/stdc++.h>
using namespace std;

int n, t;
const int T = 25;
int dur[T];

int main() {
    while (cin >> n >> t) {
        for (int i = 0; i < t; i++) {
            cin >> dur[i];
        }

        int answer = 0, bestqtd = 0, bestmask = 0;
        for (int mask = 0; mask < (1 << t); mask++) {
            int dur_total = 0;
            for (int i = 0; i < t; i++) {
                if (mask & (1 << i)) {
                    dur_total += dur[i];
                }
            }
            int qtd = __builtin_popcount(mask);

            if (dur_total > n)
                continue;

            if (dur_total > answer || (dur_total == answer && qtd > bestqtd)) {
                answer = dur_total;
                bestqtd = qtd;
                bestmask = mask;
            }
        }

        for (int i = 0; i < t; i++) {
            if (bestmask & (1 << i)) {
                cout << dur[i] << " ";
            }
        }
        cout << "sum:" << answer << "\n";
    }
    return 0;
}
