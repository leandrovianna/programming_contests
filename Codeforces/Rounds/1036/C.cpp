// Codeforces - Classy Numbers - 1036C - EduRound
#include <bits/stdc++.h>
using namespace std;

vector<int64_t> ans;

void brute(int pos, int cnt, int64_t num) {
    if (pos == 18) {
        ans.push_back(num);
    } else {
        // colocando um zero em pos
        brute(pos+1, cnt, num * 10);

        // caso tivemos menos de 3 nao zero digitos
        // adicionar mais um
        if (cnt < 3) {
            for (int d = 1; d <= 9; d++) {
                brute(pos+1, cnt+1, num * 10 + d);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    int64_t l, r;

    brute(0, 0, 0);
    // unico numero com 19 digitos
    ans.push_back(1000000000000000000);

    cin >> t;

    while (t--) {
        cin >> l >> r;

        auto it1 = upper_bound(ans.begin(), ans.end(), r);
        auto it2 = lower_bound(ans.begin(), ans.end(), l);
        cout << it1 - it2 << "\n";
    }
    return 0;
}
