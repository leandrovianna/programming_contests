// Codeforces - Two distinct points - 1108A - Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    int l1, r1, l2, r2;

    cin >> q;
    
    while (q--) {
        cin >> l1 >> r1
            >> l2 >> r2;

        cout << l1 << " ";
        if (l1 == l2)
            l2++;

        cout << l2 << "\n";
    }
    return 0;
}
