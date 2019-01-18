// Codeforces - Doors Breaking and Repairing - 1102C Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, cnt = 0;

    cin >> n >> x >> y;

    for (int i = 0, z; i < n; i++) {
        cin >> z;
        if (z <= x) {
            cnt++;
        }
    }

    cout << (x > y ? n : (cnt+1) / 2) << endl;

    
    return 0;
}
