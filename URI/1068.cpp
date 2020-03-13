// URI - Balanço de Parênteses I - 1068
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;

    while (cin >> line) {
        bool ans = true;
        int open = 0;
        for (const auto &ch : line) {
            if (ch == '(')
                open++;
            else if (ch == ')') {
                if (open == 0) {
                    ans = false;
                    break;
                }

                open--;
            }
        }

        if (open != 0)
            ans = false;

        cout << (ans ? "correct" : "incorrect") << "\n";
    }

    return 0;
}
