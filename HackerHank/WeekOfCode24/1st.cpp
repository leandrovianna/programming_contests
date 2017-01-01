#include <iostream>
#include <vector>
using namespace std;

int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
    }
    
    int qtd = 0;
    for(int apple_i = 0;apple_i < m;apple_i++){
        int x = a + apple[apple_i];
        if (x >= s && x <= t)
            qtd++;
    }
    
    cout << qtd << endl;
    
    qtd = 0;
    for(int orange_i = 0;orange_i < n;orange_i++){
       int x = b + orange[orange_i];
        if (x >= s && x <= t)
            qtd++;
    }
    
    cout << qtd << endl;
    return 0;
}
