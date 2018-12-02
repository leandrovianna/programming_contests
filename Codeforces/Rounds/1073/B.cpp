// Codeforces - Vasya and Books - 1073B Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
int a[N];
map<int, int> pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int pointer = 0;

    for (int j = 0, x; j < n; j++) {
        cin >> x;
        cout << max(0, pos[x] - pointer + 1) << " ";
        pointer = max(pos[x] + 1, pointer);
    }
    cout << "\n";

    return 0;
}
