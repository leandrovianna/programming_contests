// Codeforces - Walking Between Houses - 1015D Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, k, s;

    cin >> n >> k >> s;

    int64_t min_moves = (s+n-2) / (n-1);

    if (min_moves <= k && k <= s) {
        int pos = 1;
        vector<int> answer;
        int64_t qtd = 0;

        for (int i = 0; i < min_moves; i++) {
            for (int j = 1; j < n-1 && qtd < k - min_moves; j++) {
                answer.push_back((pos == 1) ? pos + j : pos - j);
                qtd++;
            }

            if (i == min_moves-1 && s % (n-1) > 0) {
                answer.push_back((pos == 1) ? pos + s % (n-1) : pos - s % (n-1));
                break;
            }

            pos = (pos == 1) ? n : 1;
            answer.push_back(pos);
        }

        cout << "YES\n";
        for (const auto &p : answer) {
            cout << p << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
