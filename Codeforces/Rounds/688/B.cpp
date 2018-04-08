//Codeforces - Lovely Palindromes - 688B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num;
    cin >> num;

    cout << num;
    reverse(num.begin(), num.end());
    cout << num << endl;
    return 0;
}
