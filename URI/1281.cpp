// URI - Ida à Feira - 1281
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p, qtd;
    string name;
    double value;
    map<string, double> price_table;
    
    cin >> n;
    
    cout << fixed << setprecision(2);
    
    while (n--) {
        cin >> m;
        
        for (int i = 0; i < m; i++) {
            cin >> name >> value;
            
            price_table[name] = value;
        }
        
        cin >> p;
        
        double ans = 0;
        for (int i = 0; i < p; i++) {
            cin >> name >> qtd;
            
            ans += price_table[name] * qtd;
        }
        
        cout << "R$ " << ans << "\n";
    }
    
    return 0;
}
