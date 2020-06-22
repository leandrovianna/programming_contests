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
	int a, b, c, d, t;	

	cin >> a >> b >> c >> d >> t;

	int dif = abs(a - c) + abs(b - d);
	int x = t - dif;

	if (x >= 0 && x % 2 == 0)
		cout << "Y" << endl;
	else
		cout << "N" << endl;
	return 0;
}
