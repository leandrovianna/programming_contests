// TAP 2018/2 - Superdelegates - E2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int ca, cb, pa, pb, u;

    cin >> ca >> cb >> pa >> pb >> u;

    for (int v = 0; v <= u; v++) {
        if (ca + pa + v > cb + pb + u - v) {
            cout << "Candidate A needs at least " << v
                << " of the unpledged superdelegates." << endl;
            return 0;
        }
    }

    cout << "Candidate A has lost the nomination!" << endl;
    return 0;
}
