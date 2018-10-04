// TAP 2018/2 - Enigma
#include <bits/stdc++.h>
using namespace std;

bool readChar(char &c) {
	c = getchar_unlocked();
	return c != EOF;
}

inline void writeChar(char c) {
	putchar_unlocked(c);
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
    string a, b;
    char ch;

    while (readChar(ch) && ch != '\n') {
        a += ch;
    }

    while (readChar(ch) && ch != '\n') {
        b += ch;
    }

    int count = 0;
    for (int i = 0, sza = a.size(), szb = b.size(); 
            i < sza - szb + 1; i++) {
        count++;
        for (int j = 0; j < szb; j++) {
            if (a[i+j] == b[j]) {
               count--; 
               break;
            }
        }
    }

    writeInt(count);
    writeChar('\n');
    return 0;
}
