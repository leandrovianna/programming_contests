//Spoj - Horrible Queries - HORRIBLE
#include <bits/stdc++.h>
using namespace std;

const int N = 2*1e5+10;

int bit[N];

// execute the query [1, x]
int query(int x) {
	int s = 0;
	
	while (x) {
		s += bit[x];
		x -= (x & -x);
	}

	return s;
}

// execute the update [1,x]
void update(int x, int v) {
	while (x <= N) {
		bit[x] += v;
		x += (x & -x);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, c;
    int type;
    int p, q, v;
    cin >> t;

    while (t--) {
        memset(bit, 0, sizeof(bit));
        cin >> n >> c;
        for (int i = 0; i < c; i++) {
            cin >> type;
            if (type == 0) {
                cin >> p >> q >> v;
                // update [p+1, q+1]
                update(q+1, v);
                update(p, -v);
            } else {
                cin >> p >> q;
                // query [p+1, q+1]
                int64_t ans = query(q+1);
                ans -= query(p);
                cout << ans << endl;
            }
        }
    }
    return 0;
}
