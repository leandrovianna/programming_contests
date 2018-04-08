//Codeforces - Sort the Array - 451B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const int N = 100100;
    int n, a[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
       cin >> a[i]; 
    }

    int l1 = 0, l2 = 0;
    bool desc = false;
    for (int i = 1; i < n; i++) {
        if (!desc && a[i] < a[i-1]) {
            desc = true;
            l1 = i-1;
        }

        if (desc && a[i] > a[i-1]) {
            desc = false;
            l2 = i-1;
            break;
        }
    }

    if (desc) {
        l2 = n-1;
    }

    reverse(a+l1, a+l2+1);

    bool yes = true;
    for (int i = 1; i < n; i++) {
        if (a[i-1] > a[i]) {
            yes = false;
            break;
        }
    }

    if (yes) {
        cout << "yes\n" << l1+1 << " " << l2+1 << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
