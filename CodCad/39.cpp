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

i64 fac(int n) {
	i64 r = 1;
	for (int i = 2; i <= n; i++)
		r *= i;
	return r;
}

int main() {
	int n;

	cin >> n;

	cout << fac(n) << endl;
	return 0;
}
