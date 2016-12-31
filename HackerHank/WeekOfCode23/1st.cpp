#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q, x;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> x;
        cout << (x % 2 ? "No" : "Yes") << endl;
    }
    return 0;
}
