// Codeforces - Inscribed Figures - 1156A Edu Round
#include <bits/stdc++.h>
using namespace std;

const int CIRCLE = 1, TRI = 2, SQUARE = 3;
const int N = 110;
int a[N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int p, answer = 0;
    bool infinite = false;

    for (int i = 1, x; i < n; i++) {
        x = a[i];
        p = a[i-1];
        
        if (p == CIRCLE) {
            if (x == TRI) {
                answer += 3;
                if (i >= 2 && a[i-2] == SQUARE)
                    answer--;
            }
            else if (x == SQUARE)
                answer += 4;
        } else if (p == TRI) {
            if (x == CIRCLE) 
                answer += 3;
            else if (x == SQUARE)
                infinite = true;
        } else if (p == SQUARE) {
            if (x == CIRCLE)
                answer += 4;
            else if (x == TRI)
                infinite = true;
        }

        p = x;
    }

    if (infinite)
        cout << "Infinite\n";
    else
        cout << "Finite\n" << answer << "\n";

    return 0;
}
