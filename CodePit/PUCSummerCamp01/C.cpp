//Puc Summer Camp 2018
//URI - Schweisen - 1112
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

	int x, y, p, q;
	int a, b, c, d;
	char ch;

	while (cin >> x >> y >> p, x || y || p) {
		memset(ft, 0, sizeof(ft));
		cin >> q;
		for (int i = 0; i < q; i++) {
			cin >> ch;
			switch (ch) {
				case 'A':
					cin >> a >> b >> c;
					update(b+1, c+1, a);
					break;
				case 'P':
					cin >> a >> b >> c >> d;
					if (c < a) swap(c, a);
					if (d < b) swap(d, b);

					cout << sum(a+1, b+1, c+1, d+1) * p << endl;
					break;
			}
		}
		cout << endl;
	}

	return 0;
}
