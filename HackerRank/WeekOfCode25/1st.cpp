#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    int m;
    int qtd = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0;b_i < m;b_i++){
       cin >> b[b_i];
    }
    
    for (int i = a[n-1], j; i <= b[m-1]; i++) {
        for (j = 0; j < n; j++) {
            if (i % a[j] != 0)
                break;
        }
        if (j != n)
            continue;
        
        for (j = 0; j < m; j++) {
            if (b[j] % i != 0)
                break;
        }
        if (j != m)
            continue;
        
        qtd++;
    }
    
    cout << qtd << endl;
    return 0;
}
