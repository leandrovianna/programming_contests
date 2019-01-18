// Codeforces - Integer Sequence Dividing - 1102A Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;

    cin >> n;
    n = n * (n+1) / 2;
    cout << (n & 1LL) << endl;
    return 0;
}
