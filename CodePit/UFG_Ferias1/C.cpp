// WA
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

int main() {
	int a, p, n, x, y, volta, r;

	cin >> a >> p;
	for (int i = 0; i < a; i++) {
		cin >> n;
		y = 0;
		volta = 1;
		for (int j = 0; j < n; j++) {
			cin >> x;

			if (x < y && (x != 0 || j != n-1))
				volta++;

			y = x;
		}

		r = max(r, volta);
	}

	cout << r << endl;
	return 0;
}
