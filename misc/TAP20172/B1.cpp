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
	int n, k;

	cin >> n >> k;
	int r = n;
	for (int i = 0; i < k; i++)
		r += (n *= 10);

	cout << r << endl;
	return 0;
}
