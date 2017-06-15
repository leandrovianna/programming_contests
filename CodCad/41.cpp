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

i64 solve(int n) {
	if (n == 1) return 0;

	if (n % 2) return 1 + solve(3*n+1);
	else return 1 + solve(n/2);
}

int main() {
	int n;

	cin >> n;

	cout << solve(n) << endl;
	return 0;
}
