// In contest - WA - Test 9
// 01/01/2017 - Accepted
#include <iostream>
#include <string>
using namespace std;

int sayNo() {
    cout << "NO" << endl;
    return 0;
}

int main() {
    int n;
    long km, total;
    string d;

    cin >> n;
    total = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> km >> d;
        
        if (total == 20000 && d != "North") {
            return sayNo();
        }
        
        if (total == 0 && d != "South") {
            return sayNo();
        }
        
        if (d == "South") {
            total += km;
            if (total > 20000)
                return sayNo();
        } else if (d == "North") {
            total -= km;
            if (total < 0)
                return sayNo();
        }
    }
    
    if (total == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
        
	return 0;
}
