#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;

    cin >> s;
    n = s.size();

    if (n <= 20) {
        cout << "1 " << n << "\n";
        cout << s << "\n";
        return 0;
    }

    for (int l = 2; l <= 5; l++) {
        int v = (n+l-1) / l;
        if (v <= 20) {
            cout << l << " " << v << "\n";
            int r = l - n % l, h;
            if (n % l == 0)
                r = 0;
            for (int i = 0, pos = 0; i < l; i++) {
                h = v;
                if (r > 0) {
                    h--;
                    r--;
                    cout << "*";
                }
                for (int j = 0; j < h; j++) {
                    cout << s[pos+j];
                }
                cout << "\n";
                pos += h;
            }
            break;
        }
    }
    return 0;
}
