#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, e;
    string s;
    int n;

    c = 0;
    e = 0;
    
    int ans_c = 0;
    int ans_e = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "chuva") {
            c--;
            e++;
        }

        ans_c = min(ans_c, c);
        ans_e = min(ans_e, e);

        cin >> s;
        if (s == "chuva") {
            c++;
            e--;
        }

        ans_c = min(ans_c, c);
        ans_e = min(ans_e, e);

    }

    cout << abs(ans_c) << " " << abs(ans_e) << "\n";
    return 0;
}
