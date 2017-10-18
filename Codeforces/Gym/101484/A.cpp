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

int main() {
	ios::sync_with_stdio(false);
	int n, x, y;
	bool r1, r2, r3;
	r1 = r2 = r3 = false;

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> y;
		if (y == x) r3 = true;
		if (y < x) r1 = true;
		if (y > x) r2 = true;
	}

	cout << (r3 ? "1" : (r1 && r2 ? "2" : "-1")) << endl;
	return 0;
}
