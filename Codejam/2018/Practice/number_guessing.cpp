//CodeJam 2018 Practice - Number Guessing
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t, a, b, n, q;
    string resp;
    bool correct;

    cin >> t;
    while (t--) {
        cin >> a >> b >> n;

        correct = false;
        a++;
        while (n--) {
            q = (b - a) / 2 + a;

            cout << q << endl;

            cin >> resp;

            if (resp == "CORRECT") {
                correct = true;
                break;
            } else if (resp == "TOO_BIG") {
                b = q - 1;
            } else if (resp == "TOO_SMALL") {
                a = q + 1;
            } else if (resp == "WRONG_ANSWER") {
                return 0;
            }
        }

        if (!correct) {
            cin >> resp;
            if (resp == "WRONG_ANSWER") {
                return 0;
            }
        }
    }

    return 0;
}
