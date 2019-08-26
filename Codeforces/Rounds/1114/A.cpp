// Codeforces - Got Any Grapes - 1114A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    int a, b, c;

    cin >> x >> y >> z;
    cin >> a >> b >> c;

    if (a >= x && (a - x) + b >= y && (a - x) + b - y + c >= z) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
