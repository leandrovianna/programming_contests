//URI - Carteiro - 2448
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m, id;
    map<int, int> pos;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
       cin >> id; 
       pos[id] = i;
    }

    int pos_atual = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
       cin >> id; 
       ans += abs(pos_atual - pos[id]);
       pos_atual = pos[id];
    }

    cout << ans << endl;
    return 0;
}
