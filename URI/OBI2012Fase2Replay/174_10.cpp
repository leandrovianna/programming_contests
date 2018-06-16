#include <iostream>
 
using namespace std;
 
int main() {
 
    int x, y;
    cin >> x >> y;
    if (x >= 0 && x <= 432)
        if (y >= 0 && y <= 468) {
            cout << "dentro" << endl;
            return 0;
        }
    
    cout << "fora" << endl;
 
    return 0;
}
