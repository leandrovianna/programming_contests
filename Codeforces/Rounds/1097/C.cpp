// Codeforces - Yuhao and a Parenthesis - 1097C Hello 2019
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
pair<int, int> br[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        int open = 0;
        for (const auto &ch : s) {
            if (ch == '(')
                open++;
            else if (open == 0)
                br[i].first++;
            else
                open--;
        }

        br[i].second = open;
    }

    int correct = 0;
    multiset<int> values;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (br[i].first == 0 && br[i].second == 0) {
            correct++;
        } else if (br[i].first == 0 || br[i].second == 0) {
            int v = br[i].first == 0 ? br[i].second : -br[i].first;
            auto it = values.find(-v);

            if (it != values.end()) {
                values.erase(it);
                answer++;
            } else {
                values.insert(v);
            }
        }
    }

    answer += correct / 2;

    cout << answer << endl;

    return 0;
}
