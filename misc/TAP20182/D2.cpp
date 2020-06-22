// TAP 2018/2 - Ultimate Loser - D2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tree[150];
    int n, k;

    cin >> n;

    for (int i = 0; i < n; i++) {
        tree[i] = i+1;
    }
    k = n;

    for (int i = 1, x; i < n; i++) {
        cin >> x;
        tree[k++] = x;
    }

    reverse(tree, tree+k);

    int pos = 0;
    while (2*pos+1 < k && 2*pos+2 < k) {
        if (tree[2*pos+1] == tree[pos]) {
            pos = 2*pos+2;
        } else {
            pos = 2*pos+1;
        }
    }

    cout << "The ultimate loser is team " << tree[pos] << "." << endl;
    return 0;
}
