#include <bits/stdc++.h>
using namespace std;

#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

bool readChar(char &c) {
	c = getchar_unlocked();
	return c != EOF;
}

inline void writeChar(char c) {
	putchar_unlocked(c);
}

template<typename T>
bool readInt( T &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 
 
template<typename T>
inline void writeInt(T n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

int main() {
	ios::sync_with_stdio(false);
	
	int x;
	while (readInt(x)) {
		writeInt(x);
	}
	return 0;
}

