// Live Archive - 4214 - Electricity
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
struct {
    int d, m, y;
    int64_t c;
} ts[N];

int leap(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        return 1;
    else
        return 0;
}

int daysmouth(int m, int y) {
    switch (m) {
        case 1:
            return 31;
        case 2:
            return 28 + leap(y);
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }

    return 0;
}

// true if day i is day after of day j
bool dayafter(int i, int j) {
    return ((ts[j].y == ts[i].y 
                && ts[j].m == ts[i].m 
                && ts[j].d + 1 == ts[i].d)
            || (((ts[j].y == ts[i].y && ts[j].m + 1 == ts[i].m)
                || (ts[j].y + 1 == ts[i].y && ts[j].m == 12 && ts[i].m == 1))
                && (ts[j].d == daysmouth(ts[j].m, ts[j].y) && ts[i].d == 1))
                );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> ts[i].d
                >> ts[i].m
                >> ts[i].y
                >> ts[i].c;
        }

        int anscount = 0;
        int64_t cost = 0;
        for (int i = 1; i < n; i++) {
            if (dayafter(i, i-1)) {
                cost += ts[i].c - ts[i-1].c;
                anscount++;
            }
        }

        cout << anscount << " " << cost << "\n";
    }
    return 0;
}
