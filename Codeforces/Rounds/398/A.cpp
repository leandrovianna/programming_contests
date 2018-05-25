#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b;
    int64_t score = 0;
    string out = "";

    cin >> a >> b;

    if (a >= b) {
        score = - ceil(b / 2.0) * ceil(b / 2.0)
            + a * a
            + - (b / 2) * (b / 2);
        out = string((int)ceil(b / 2.0), 'x')
            + string(a, 'o')
            + string(b / 2, 'x');
    } else {
        score = 0;
        int cb = b, ca = a;
        int cc = b % (a+1);
        while (cb) {
            for (int i = 0; i < b/(a+1); i++) {
                if (cb > 0) {
                    out += 'x';
                    cb--;
                } else break;
            }
            if (cc > 0) {
                out += 'x';
                cb--;
                cc--;
            }
            if (ca > 0) {
                out += 'o';
                ca--;
            }
        }

        char prev = 's';
        int64_t curr = 0;
        for (const auto &c : out) {
            if (c == prev) {
                curr++;
            } else {
                score += (prev == 'x' ? -1 : 1) * curr * curr;
                prev = c;
                curr = 1;
            }
        }

        score += (prev == 'x' ? -1 : 1) * curr * curr;
    }
    
    cout << score << endl
        << out << endl;
    return 0;
}
