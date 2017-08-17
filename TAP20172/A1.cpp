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
	int x, y, r = 0;
	cin >> x >> y;

	if (x > 0 && y > 0)
		r = 1;
	if (x > 0 && y < 0)
		r = 4;
	if (x < 0 && y > 0)
		r = 2;
	if (x < 0 && y < 0)
		r = 3;

	cout << r << endl;
	return 0;
}
