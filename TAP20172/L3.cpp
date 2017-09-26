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
	int area = 0;
	int x, y;

	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		area += x * y;
	}

	int l = sqrt(area);

	cout << (l * l == area ? "YES" : "NO") << endl;

	return 0;
}
