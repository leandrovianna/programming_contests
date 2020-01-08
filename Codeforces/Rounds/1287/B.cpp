// Codeforces - Hyperset - 1287B
#include <bits/stdc++.h>
using namespace std;

const int N = 1510;
string cards[N];

char getMissing(char c1, char c2) {
    const char TYPES[] = {'S', 'T', 'E'};
    bool mark[] = {false, false, false};

    for (int i = 0; i < 3; i++) {
        if (TYPES[i] == c1 || TYPES[i] == c2)
            mark[i] = true;
    }

    for (int i = 0; i < 3; i++) {
        if (!mark[i])
            return TYPES[i];
    }

    return TYPES[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    sort(cards, cards+n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            string nextcard = string(k, '*');

            for (int l = 0; l < k; l++) {
                if (cards[i][l] == cards[j][l]) {
                    nextcard[l] = cards[i][l];
                } else {
                    nextcard[l] = getMissing(cards[i][l], cards[j][l]);
                }
            }

            if (binary_search(cards, cards+n, nextcard)) {
                ans++;
            }
        }
    }

    cout << ans / 3 << "\n";
    return 0;
}
