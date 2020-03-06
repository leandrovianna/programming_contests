#include <bits/stdc++.h>
using namespace std;

template<typename T>
T ext_gcd(T a, T b, T &x, T &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	
	T x1, y1;
	T d = ext_gcd(b % a, a, x1, y1);

	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int64_t a, b;
	
	while (cin >> a >> b) {
		if (a == b) {
			cout << "0 1 " << a << "\n";
		} else {
			int64_t d, x, y;
			d = ext_gcd(a, b, x, y);
	
			cout << x << " " << y << " " << d << "\n";
		}
	}
	
	return 0;
}
