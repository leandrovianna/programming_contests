// Codeforces - Tree Diameter - 1146C - Forethought Future Cup - Elimination Round
#include <bits/stdc++.h>
using namespace std;

const int Q = 9;
vector<int> sets[Q][2];

void gen_sets(int l, int r, int depth) {
    if (depth == Q) return;

    if (l == r) sets[depth][0].push_back(l);
    else {
        int mid = (l + r) / 2;

        for (int i = l; i <= r; i++) {
            sets[depth][i <= mid ? 0 : 1].push_back(i);
        }

        gen_sets(l, mid, depth + 1);
        gen_sets(mid+1, r, depth + 1);
    }
}

int main() {
    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;

        int answer = 0;
        gen_sets(1, n, 0);

        for (int q = 0, d; q < min(n-1, Q); q++) {
            size_t size1 = sets[q][0].size(), size2 = sets[q][1].size();
            if (size1 == 0 || size2 == 0) continue;

            cout << size1 << " " << size2 << " ";
            for (const auto &u : sets[q][0]) {
                cout << u << " ";
            }
            for (const auto &u : sets[q][1]) {
                cout << u << " ";
            }
            cout << endl;

            cin >> d;
            if (d == -1) // invalid query
                return 0;

            answer = max(answer, d);
        }

        for (int q = 0; q < Q; q++) {
            sets[q][0].clear();
            sets[q][1].clear();
        }

        cout << "-1 " << answer << endl;
    }
    return 0;
}
