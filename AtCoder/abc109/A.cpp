// AtCoder - ABC333 - abc109A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, d;

    cin >> a >> b;

    d = a * b;
    if (d % 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
