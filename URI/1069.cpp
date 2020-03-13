// URI - Diamantes e Areia - 1069
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string line;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> line;
        
        int open = 0, ans = 0;
        for (const auto &ch : line) {
            if (ch == '<')
                open++;
            else if (ch == '>') {
                if (open > 0) {
                    ans++;
                    open--;
                }
            }
          
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
