// TAP 2018-2 - Obras - C9
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
pair<int, int> vigas[N];
bool deleted[N];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> vigas[i].first >> vigas[i].second;
    }

    sort(vigas, vigas+n);

    int qtd = n;
    for (int i = 0; i < n-1; i++) {
        if (vigas[i].second >= vigas[i+1].first) {
            deleted[i] = true;
            qtd--;
            vigas[i+1].first = min(vigas[i].first, vigas[i+1].first);
            vigas[i+1].second = max(vigas[i].second, vigas[i+1].second);
        }
    }

    cout << qtd << "\n";
    for (int i = 0; i < n; i++) {
        if (!deleted[i]) {
            cout << vigas[i].first << " " << vigas[i].second << "\n";
        }
    }
    return 0;
}
