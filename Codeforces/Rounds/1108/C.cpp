// Codeforces - Nice Garland - 1108C
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    string perm = "BGR";
    int answer = n;
    string best_perm = perm;
    do {
        int cost = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != perm[i % 3]) {
                cost++;
            }
        }

        if (answer > cost) {
            best_perm = perm;
            answer = cost;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << answer << "\n";
    for (int i = 0; i < n; i++) {
        cout << best_perm[i % 3];
    }
    cout << "\n";
    return 0;
}
