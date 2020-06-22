// TAP 2018/2 - Computadores
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1010;
    int n, m;
    pair<int, int> comp[N];

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        // preco, qtd comp
        cin >> comp[i].first >> comp[i].second;
    }

    // ordenacao
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (comp[j] < comp[i]) {
                swap(comp[i], comp[j]);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int qt = min(comp[i].second, m / comp[i].first);
        if (qt > 0) {
            m -= qt * comp[i].first;
            ans += qt;
        }
    }

    cout << ans << endl;
    return 0;
}
