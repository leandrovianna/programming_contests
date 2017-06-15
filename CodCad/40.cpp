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

i64 sum(int n) {
	i64 r = 0;
	for (int i = 1; i <= n; i++)
		r += i;
	return r;
}

int main() {
	int n;

	cin >> n;

	cout << sum(n) << endl;
	return 0;
}
