// TAP 2018/2 - B3 - Barra de chocolate
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mid;
    int x1, y1, x2, y2;

    cin >> n >> x1 >> y1 >> x2 >> y2;

    mid = n / 2;

    if ((min(x1, x2) <= mid && mid < max(x1, x2))
            || (min(y1, y2) <= mid && mid < max(y1, y2))) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}
