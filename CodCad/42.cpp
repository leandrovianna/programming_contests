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

i64 fib(int n) {
	if (n < 2) return 1;
	else return fib(n-1) + fib(n-2);
}

int main() {
	int n;

	cin >> n;

	cout << fib(n) << endl;
	return 0;
}
