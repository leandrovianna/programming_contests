//Codeforces - Word Capitalization - 281A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    str[0] &= ~32;
    cout << str << endl;
    return 0;
}
