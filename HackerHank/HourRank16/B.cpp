//12.50 pts - Seg Fault
//2017-01-02 16:40 - Accepted - Using map to cache results
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<int, int> t;

bool test(long long n) {
    if (t.find(n) != t.end())
        return t[n];
	else if (n % 4 == 0 || n % 7 == 0)
		return t[n] = 1;
    else {
        return t[n] = (test(n-4) || test(n-7));
    }
}

int main() {
    int q;
    cin >> q;

    t[1] = 0;
    t[2] = 0;
    t[3] = 0;
    t[4] = 1;
    t[5] = 0;
    t[6] = 0;
    t[7] = 1;
    
    for(int a0 = 0; a0 < q; a0++) {
        long long n;
        cin >> n;
        
        if (test(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
