#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t x, y, n;
    
    cin >> n >> x >> y;

    int64_t a, b;
    a = min(x,y) - 1 + max(x,y) - min(x,y);
    b = n - max(x,y) + max(x,y) - min(x,y);

    if (a <= b)
        cout << "White" << endl;
    else
        cout << "Black" << endl;
    return 0;
}
