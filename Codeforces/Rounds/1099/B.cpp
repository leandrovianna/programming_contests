// Codeforces - Squares and Segments - 1099B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int l1 = 1, l2 = 1;
    bool flag = true;

    while (l1 * l2 < n) {
        if (flag) l1++;
        else l2++;
        flag = !flag;
    }

    cout << l1 + l2 << endl;
    return 0;
}
