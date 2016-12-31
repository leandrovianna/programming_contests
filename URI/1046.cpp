#include <iostream>
 
using namespace std;
 
int main() {
 
    int a, b;
    cin >> a >> b;
    int d = (b - a);
    
    if (d == 0) d = 24;
	else if (d < 0) d += 24;

    cout << "O JOGO DUROU " << d << " HORA(S)" << endl;
    return 0;
}
