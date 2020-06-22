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
	const int N = 1e5+10;
	int n, v[N];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v, v+n);

	int x = 1e9, d;
	for (int i = 0; i < n/2; i++) {
		d = v[i] + v[n-i-1];
		x = min(x, d);
	}

	cout << x << endl;
	return 0;
}
