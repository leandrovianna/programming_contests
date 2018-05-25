#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, s, p;

    cin >> k >> n >> s >> p;

    int sheets = ceil((n) / (double) s);
    int packs = ceil((k * sheets) / (double) p);
    cout << packs << endl;
    return 0;
}
