// Codeforces - Shares
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;

    fstream fin("j.in");

    while (fin >> n >> s) {
        cout << s / (n+1) << "\n";
    }

    return 0;
}
