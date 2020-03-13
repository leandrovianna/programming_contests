#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ti = 1, n, q;
    
    while (cin >> n >> q, n || q) {
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v, v+n);
        
        cout << "CASE# " << ti << ":\n";
        for (int qi = 0, x; qi < q; qi++) {
            cin >> x;
            
            int lo = 0, hi = n-1, mid, found = -1;
            
            while (lo <= hi) {
                mid = (lo + hi) >> 1;
                
                if (v[mid] == x) {
                    found = mid;
                    hi = mid-1;
                } else if (v[mid] < x) {
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
            
            if (found == -1)
                cout << x << " not found\n";
            else
                cout << x << " found at " << found+1 << "\n";
        }
        
        ti++;
    }    
    return 0;
}
