// Codeforces - Books Queries - 1066C Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 5 * 100 * 1000 + 10;
int a[N];
int pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    int id;
    char op;
    int p1 = 2 * 100 * 1000 + 10;
    int p2 = p1;

    cin >> q;

    bool first = true;
    for (int i = 0; i < q; i++) {
        cin >> op >> id;
        switch (op) {
            case 'L':
                if (!first)
                    p1--;
                first = false;
                pos[id] = p1;
                break;
            case 'R':
                if (!first)
                    p2++;
                first = false;
                pos[id] = p2;
                break;
            case '?':
                cout << min(pos[id] - p1, p2 - pos[id]) << "\n";
                break;
        }
    }
    return 0;
}
