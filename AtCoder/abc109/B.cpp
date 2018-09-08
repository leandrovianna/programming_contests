// AtCoder - Shiritori - abc109B
#include <bits/stdc++.h>
using namespace std;

int main() {
    string w;
    char ch;
    set<string> ss;
    int n;

    cin >> n;

    bool ans = true;
    for (int i = 0; i < n; i++) {
        cin >> w;
        if (ss.count(w)) 
            ans = false;

        if (i > 0 && w[0] != ch)
            ans = false;

        ch = w[w.size()-1];
        ss.insert(w);
    }

    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
