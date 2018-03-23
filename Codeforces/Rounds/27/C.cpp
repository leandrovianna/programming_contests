//Codeforces - Unordered Sequence - 27C Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    const int N = 100100;
    int n, v[N];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int pos = 0;
    for (int i = 1; i < n-1; i++) {
        if ((v[0] < v[i] && v[i] > v[i+1])
                || (v[0] > v[i] && v[i] < v[i+1]))
            pos = i;
    }

    if (pos == 0) {
        cout << 0 << endl;
    } else {
        cout << 3 << endl;
        cout << 1 << " " << pos+1 << " " << pos+2 << endl;
    }

    return 0;
}
