// AtCoder - Beginner Contest - 1 Dimensional World's Tale - B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y, minY, maxX;

    cin >> n >> m >> x >> y;

    minY = y;
    maxX = x;

    for (int i = 0, c; i < n; i++) {
        cin >> c;
        maxX = max(maxX, c);
    }

    for (int i = 0, c; i < m; i++) {
        cin >> c;
        minY = min(minY, c);
    }

    if (maxX < minY)
        cout << "No War" << endl;
    else
        cout << "War" << endl;
    return 0;
}
