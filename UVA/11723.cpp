//UVA - Numbering Roads - 11723
#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, n, ti = 1;
    
    while (cin >> r >> n, n || r) {
        int y = (r - n) / n + ((r - n) % n != 0);
        cout << "Case " << ti << ": ";
        if (r <= n)
            cout << "0\n";
        else if (y > 26)
            cout << "impossible\n";
        else
            cout << y << "\n";
        ti++;
    }
    return 0;
}
