#include <bits/stdc++.h>
using namespace std;

typedef __int128 int128_t;

std::ostream& operator<<( std::ostream& dest, __int128_t value ) {
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

int128_t gcd_extended(int128_t a, int128_t b, int128_t& x, int128_t& y){
    if(a < 0){
        int128_t d = gcd_extended(-a, b, x, y);
        x = -x; return d;
    }
    if(b < 0){
        int128_t d = gcd_extended(a, -b, x, y);
        y = -y; return d;
    }
     
    x = 1; y = 0;
    int128_t nx = 0, ny = 1, q;
     
    while(b){
        q = a/b;
        x -= q*nx; swap(x, nx);
        y -= q*ny; swap(y, ny);
        a -= q*b; swap(a, b);
    }
    return a;
}


int128_t chinese_remainder(vector<int128_t>& a, vector<int128_t>& m){
    vector<int128_t> y(a.size()), M(a.size(), 1);
     
    int128_t aux, res = 0, MM = 1;
     
    for (size_t i = 0; i < a.size(); i++){
        for (size_t j = 0; j < a.size(); j++){
            if(i != j)
            M[j] = (M[j]*m[i])%m[j];
        }
        //sem o mod para modulo prod(mi)
        MM *= m[i];
    }
     
    for (size_t i = 0; i < a.size(); i++){
        gcd_extended(M[i], m[i], y[i], aux);
        aux = a[i]*y[i] % MM;
        aux = aux * MM/m[i] % MM;
        res = (res + aux) % MM;
    }
     
    return (res + MM) % MM;
     
}

int main() {
    int b, z;
    int v[11][110];

    cin >> b >> z;

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < z+1; j++) {
            cin >> v[i][j];
        }
    }
    return 0;
}
