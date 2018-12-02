// Codeforces - Dwarves, Hats and Extrasensory Abilities - 1064E Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string out, first;
    cin >> n;

    int p1 = 0, p2 = 1e9;

    cout << p2 << " 5" << endl;
    cin >> first;

    for (int i = 0; i < n-1; i++) {
        cout << (p1+p2)/2 << " 5" << endl;
        cin >> out;
        if (out == first)
            p2 = (p1+p2)/2;
        else
            p1 = (p1+p2)/2;
    }

    cout << p1 << " 0 " << p2 << " 10" << endl;

    return 0;
}
