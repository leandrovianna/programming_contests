//Codeforces - Colorful Field - 79B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, t;
    int x, y, e;

    cin >> n >> m >> k >> t;

    vector<int> wastes;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        wastes.push_back((x-1) * m + y);
    }

    sort(wastes.begin(), wastes.end());

    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        e = (x-1) * m + y;
        auto it = lower_bound(wastes.begin(), wastes.end(), e);
        int qtd = 0;

        if (it != wastes.end()) {
            if (*it == e) {
                cout << "Waste" << endl;
                continue;
            } else {
                qtd = it - wastes.begin();
            }
        } else {
            qtd = wastes.size();
        }

        switch ((e - qtd) % 3) {
            case 1:
                cout << "Carrots" << endl;
                break;
            case 2:
                cout << "Kiwis" << endl;
                break;
            case 0:
                cout << "Grapes" << endl;
                break;
        }
    }
    return 0;
}
