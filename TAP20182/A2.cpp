// TAP 2018/2 - Crypto-Math A2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n;
    string expr;

    cin >> n;
    cin.ignore();
    getline(cin, expr);

    int op1, op2, op3;

    int pos = expr.find("+");
    int pos2 = expr.find("=");

    do {
        op1 = 0;
        for (int i = 0; i < pos-1; i++) {
            op1 = op1 * 10 + digits[expr[i] - 'A'];
        }

        op2 = 0;
        for (int i = pos+2; i < pos2-1; i++) {
            op2 = op2 * 10 + digits[expr[i] - 'A'];
        }

        op3 = 0;
        for (int i = pos2+2, sz = expr.size(); i < sz; i++) {
            op3 = op3 * 10 + digits[expr[i] - 'A'];
        }

        if (op1 + op2 == op3) {
            for (int i = 0, sz = expr.size(); i < sz; i++) {
                if ('A' <= expr[i] && expr[i] <= 'Z')
                    cout << digits[expr[i] - 'A'];
                else
                    cout << expr[i];
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(digits, digits+10));

    cout << "No solution possible." << endl;
    return 0;
}
