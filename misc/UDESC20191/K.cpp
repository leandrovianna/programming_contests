#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int n, k;
int memo[N];

int calculateMex(const bitset<N> &bt) { 
    int mex = 0; 
  
    while (bt[mex]) {
        mex++; 
    }
  
    return mex; 
} 
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    bitset<N> bt;
    memo[0] = 0;
    for (int m = 1; m <= n; m++) {
        //cout << "calc " << m << endl;
        bt.reset();
        for (int i = 1; i < k && m - i >= 0; i++) {
            bt[memo[m - i]] = 1;
        }

        memo[m] = calculateMex(bt);
    }

    cout << (memo[n] > 0 ? "Peter" : "Vinicius") << "\n";
    return 0;
}
