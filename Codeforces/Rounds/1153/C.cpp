// Codeforces - Serval and Parenthesis Sequence - 1153C Div2
#include <bits/stdc++.h>
using namespace std;

int n;
string s, output;

bool test(int ini, int fim, int inc) {
    bool ans = true;
    set<int> posUnk;

    for (int i = ini; i != fim; i += inc) {
        if (s[i] == '?')
            posUnk.insert(i);
    }

    output = s;

    for (int i = ini; i != fim; i += inc) {
        if (s[i] == '(') {
            auto it = posUnk.lower_bound(i);
            if (it != posUnk.end()) {
                output[*it] = ')';
                posUnk.erase(it);
            }
        } else if (s[i] == ')') {
            auto it = posUnk.begin();  
            if (it != posUnk.end() && *it < i) {
                output[*it] = '(';
                posUnk.erase(it);
            }
        }
    }

    int m = posUnk.size();

    if (m & 1) {
        ans = false;
    } else {
        for (int i = 0, k = 0; k < m && i < n; i++) {
            if (output[i] == '?') {
                output[i] = (k < m/2 ? '(' : ')');
                k++;
            }
        }

        int countOpen = 0;
        for (int i = 0; i < n; i++) {
            if (output[i] == '(')
                countOpen++;
            else if (output[i] == ')')
                countOpen--;

            if (countOpen < 0) {
                ans = false;
                break;
            }
        }

        if (countOpen != 0) {
            ans = false;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool ans = true;

    cin >> n;
    cin >> s;

    if (s[0] == '?')
        s[0] = '(';

    if (s[n-1] == '?')
        s[n-1] = ')';

    if (n == 1 || s[0] != '(' || s[n-1] != ')') {
        ans = false;
    } else {
        output = s;
        int op = 0, q = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                op++;
            else if (s[i] == ')')
                op--;
            else
                q++;
        }

        // cout << op << " " << q << endl;

        for (int i = 0, x = 0; i < n; i++) {
            if (s[i] == '?') {
                if (2*x-q != -op) {
                    x++;
                    output[i] = '(';
                } else {
                    output[i] = ')';
                }
            }
        }

        // cout << output << endl;

        op = 0;
        for (int i = 0; i < n; i++) {
            if (output[i] == '(') {
                op++;
            } else if (output[i] == ')') {
                op--;
            }

            if (i < n-1 && op <= 0) {
                ans = false;
                break;
            }
        }

        if (op != 0) {
            ans = false;
        }
    }

    // cout << output << "\n";

    if (ans) {
        cout << output << "\n";
    } else {
        cout << ":(\n";
    }

    return 0;
}
