//Codeforces - Boy or Girls - 236A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    char c;
    set<char> ss;
    while (cin >> c) {
        ss.insert(c);
    }

    if (ss.size() % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;

    return 0;
}
