//11.25 pts - WA
#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000

int main(){
    int n,
    	mini = INF,
    	mini_i,
    	old_mini,
    	cont;

    cin >> n;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    
    for (int i = 0; i < n; i++) {
        if (c[i] < mini) {
            mini = c[i];
            mini_i = i;
        }
    }
    
    cont = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == mini) {
            cont++;
        }
    }

    c[mini_i] *= 2;
    old_mini = mini;
    mini = INF;
    
    for (int i = 0; i < n; i++) {
        if (c[i] < mini) {
            mini = c[i];
            mini_i = i;
        }
    }
    
    if (old_mini != mini)
        cout << mini << " " << cont << endl;
    else
        cout << old_mini << " " << cont << endl;
    
    return 0;
}
