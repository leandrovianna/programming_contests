#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

i64 lcm(i64 a, i64 b) {
	return a * b / __gcd(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	int n, l, resp, x;
	i64 t0, t, mt;

	cin >> n >> l;
	cin >> t0;
	for (int i = 0; i < n-1; i++) {
		cin >> x;
		t0 = lcm(t0, x);
	}

	resp = 1;
	mt = 0;
	for (int ti = 1; ti <= l; ti++) {
		t = lcm(t0, ti);

		if (mt < t && t <= l) {
			mt = t;
			resp = ti;
		}
	}

	cout << resp << endl;
	return 0;
}
