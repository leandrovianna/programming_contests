//Codeforces - Coins - 47B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    const int T = 3;
    char l1, op, l2;
    map<char, int> ptn;
    ptn['A'] = 10;
    ptn['B'] = 10;
    ptn['C'] = 10;
    int delta;

    for (int i = 0; i < T; i++) {
        cin >> l1 >> op >> l2;

        if (op == '<') {
            delta = -1;
        } else if (op == '>') {
            delta = +1;
        }

        ptn[l1] += delta;
        ptn[l2] += -delta;
    }


    vector<pair<char, int> > aux;
    for (const auto &p : ptn) {
        aux.push_back(p);
    }

    sort(aux.begin(), aux.end(), [](const auto &p1, const auto &p2) {
            return p1.second < p2.second;
            });

    for (size_t i = 1; i < aux.size(); i++) {
        if (aux[i].second == aux[i-1].second) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for (const auto &p : aux) {
        cout << p.first;
    }
    cout << endl;

    return 0;
}
