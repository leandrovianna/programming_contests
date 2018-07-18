#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, x, y, ans;

    cin >> n;
    
    int64_t lox = 1, hix = n, loy = 1, hiy = n;

    while (lox <= hix || loy <= hiy) {
        if (lox <= hix) {
            x = lox + (hix - lox) / 2LL;
        }

        if (loy <= hiy) {
            y = loy + (hiy - loy) / 2LL;
        }

        cout << x << " " << y << endl;
        fflush(stdout);

        cin >> ans;

        switch (ans) {
            case 0:
                return 0;
            case 1: // x < a
                lox = x+1;
                break;
            case 2: // y < b
                loy = y+1;
                break;
            case 3: // x > a or y > b
                if (lox < hix)
                    hix = x-1;
                else if (loy < hiy)
                    hiy = y-1;
                break;
        }
    }

    cout << x << " " << y << endl;
    fflush(stdout);

    cin >> ans;

    return 0;
}
