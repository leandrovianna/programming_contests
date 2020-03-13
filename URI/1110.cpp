// URI - Jogando Cartas Fora - 1110
#include <bits/stdc++.h>
using std::cout;
using std::cin;

const int N = 150;
int discarded[N], stack[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            stack[i] = i+1;
        }
        
        int st = 0, en = n-1, k = 0;
        
        while (st < en) {
            discarded[k++] = stack[st];
            st++;
            en++;
            stack[en] = stack[st];
            st++;
        }
        
        cout << "Discarded cards:";
        for (int i = 0; i < k; i++) {
            cout << " " << discarded[i];
            if (i < k-1)
                cout << ",";
        }
        cout << "\n" << "Remaining card: "
            << stack[st] << "\n";
    }
    
    return 0;
}
