//11.25 pts - WA
//2017-01-02 17:07 - Accepted
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }

    sort(c.begin(), c.end());
    if (c[0] != c[1]) { // tem minimal
		c[0] *= 2;
		sort(c.begin(), c.end());
		
		cout << c[0] << " " << 1 << endl;
	} else { // varios minimos
		cout << c[0] << " " << n << endl;
	}
    return 0;
}
