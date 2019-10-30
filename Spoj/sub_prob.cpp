// Spoj - Substring Problem - SUB_PROB - TLE
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

struct DoubleHash {
    uint64_t h[2][N], poww[2][N];
    uint64_t p[2], mod[2];

    DoubleHash() : DoubleHash(75, 1000000007, 232, 1000000009) {}

    DoubleHash(uint64_t p1, uint64_t mod1, uint64_t p2, uint64_t mod2) {
        p[0] = p1;
        p[1] = p2;
        mod[0] = mod1;
        mod[1] = mod2;

        for (int j = 0; j < 2; j++) {
            poww[j][0] = 1;
            for (int i = 1; i < N; i++) {
                poww[j][i] = (poww[j][i-1] * p[j]) % mod[j];
            }
        }

    }

    void init(const string &s) {
        for (int idx = 0; idx < 2; idx++) {
            h[idx][0] = 5381ULL;
            for (int i = 0, n = s.size(); i < n; i++) {
                int code = s[i];
                h[idx][i+1] = (h[idx][i] * p[idx] + code) % mod[idx];
            }
        }
    }

    pair<uint64_t, uint64_t> get_hash(int i, int j) {
        uint64_t r[2];
        for (int idx = 0; idx < 2; idx++) {
            r[idx] = (h[idx][j+1] + mod[idx]
                - (h[idx][i] * poww[idx][j-i+1]) % mod[idx]) % mod[idx];
        }
        return {r[0], r[1]};
    }
};

DoubleHash h1, h2;

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

void readString(string &s) {
    char ch = 'l';
    s = "";
    while (ch != '\n') {
        readChar(ch);
        s += ch;
    }
    s.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s = "", p;

    readString(s);
    int m = s.size();

    h1.init(s);

    readInt(n);

    for (int ni = 0; ni < n; ni++) {
        readString(p);
        h2.init(p);
        char ans = 'N';
        for (int i = 0, l = p.size(); i <= m - l; i++) {
            if (h1.get_hash(i, i+l-1) == h2.get_hash(0, l-1)) {
                ans = 'Y';
                break;
            }
        }
        writeChar(ans);
        writeChar('\n');
    }

    return 0;
}
