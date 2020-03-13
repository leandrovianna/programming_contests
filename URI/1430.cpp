// URI - Composição de Jingles - 1430
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 64;

    map<char, int> table = {
        {'W', MAX},
        {'H', MAX/2},
        {'Q', MAX/4},
        {'E', MAX/8},
        {'S', MAX/16},
        {'T', MAX/32},
        {'X', MAX/64},
    };

    string composicao;

    while (cin >> composicao, composicao[0] != '*') {

        int value = 0, ans = 0;
        for (int i = 1, n = composicao.size(); i < n; i++) {
            char &ch = composicao[i];

            if (ch == '/') {
                if (value == MAX)
                    ans++;

                value = 0;
            } else {
                value += table[ch];
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
