// Codeforces - Gennady and a Card Game - 1097A Hello 2019
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 5;
    pair<char, char> cards[N];

    for (int i = 0; i < N+1; i++) {
        cin >> cards[i].first >> cards[i].second;
    }

    bool answer = false;
    for (int i = 1; i < N+1; i++) {
        if (cards[0].first == cards[i].first ||
                cards[0].second == cards[i].second) {
            answer = true;
        }
    }

    cout << (answer ? "YES" : "NO") << "\n";
    return 0;
}
