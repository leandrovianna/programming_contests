//Lib - Fenwick Tree 2D
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int ft[N][N];

int last(int v) {
	return v & -v;
}

void update(int x, int y, int val) {
	for (int i = x; i < N; i += last(i)) {
		for (int j = y; j < N; j += last(j)) {
			ft[i][j] += val;
		}
	}
}

int query(int x, int y) {
	int s = 0;
	for (int i = x; i > 0; i -= last(i)) {
		for (int j = y; j > 0; j -= last(j)) {
			s += ft[i][j];
		}
	}
	return s;
}

int sum(int x1, int y1, int x2, int y2) {
	return query(x2, y2) - query(x2, y1 - 1)
		- query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
