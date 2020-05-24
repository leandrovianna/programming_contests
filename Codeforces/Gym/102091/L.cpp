// Codeforces - Largest Allowed Area
#include <bits/stdc++.h>
using namespace std;

#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

inline void writeChar(char c) {
    putchar_unlocked(c);
}

template<typename T>
bool readInt(T &n) {
    n = 0;
    bool neg = false;
    char c = getchar_unlocked();
    if (c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if (c == '-') neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? -n : n);
    return true;
}

template<typename T>
inline void writeInt(T n) {
    int idx = 20;
    if (n < 0) putchar_unlocked('-');
    n = abs(n);
    char out[21];
    out[20] = ' ';
    do {
        idx--;
        out[idx] = n % 10 + '0';
        n /= 10;
    } while (n);
    do { putchar_unlocked(out[idx++]); } while (out[idx] != ' ');
}

const int N = 1010;
int a[N][N], pre[N][N];

int main() {
    int t, r, c;

    readInt(t);
    while (t--) {
        readInt(r);
        readInt(c);

        for (int i = 0; i <= max(r,c); i++) {
            a[i][0] = a[0][i] = 0;
            pre[i][0] = pre[0][i] = 0;
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                readInt(a[i][j]);
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                pre[i][j] = a[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }

        /*
           for (int i = 1; i <= r; i++) {
           for (int j = 1; j <= c; j++) {
           cout << pre[i][j] << " ";
           }
           cout << endl;
           }
           */

        int lo = 1, hi = min(r,c), mid, ans = 0;

        while (lo <= hi) {
            mid = (lo + hi) / 2;

            bool ok = false;
            for (int x0 = 1; x0 <= r - mid + 1; x0++) {
                for (int y0 = 1; y0 <= c - mid + 1; y0++) {
                    int x1 = x0 + mid - 1;
                    int y1 = y0 + mid - 1;

                    int sum = pre[x1][y1] - pre[x1][y0-1] - pre[x0-1][y1] + pre[x0-1][y0-1];
                    if (sum <= 1) {
                        ok = true;
                        break;
                    }
                }

                if (ok) break;
            }

            if (ok) {
                ans = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        writeInt(ans);
        writeChar('\n');
    }
    return 0;
}
