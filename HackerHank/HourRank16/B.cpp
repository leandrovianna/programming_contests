//12.50 pts - Seg Fault
#include <iostream>
#include <cstring>
using namespace std;

#define N 100000000
int t[N];

bool test(long long n) {
    if (n < N && t[n] != -1)
        return t[n];
    else {
        return t[n] = (test(n-4) || test(n-7));
    }
}

int main(){
    int q;
    cin >> q;
    
    memset(t, -1, N);
    t[1] = 0;
    t[2] = 0;
    t[3] = 0;
    t[4] = 1;
    t[5] = 0;
    t[6] = 0;
    t[7] = 1;
    
    for(int a0 = 0; a0 < q; a0++){
        long long n;
        cin >> n;
        
        if (test(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
