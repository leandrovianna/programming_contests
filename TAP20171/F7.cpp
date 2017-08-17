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

const int N = 10;

i64 dp[N][N];

i64 solve(int ant, int x) {
	if (x == 1)
		return dp[ant][x] = 10 - ant;
	else {
		i64 r = 0;
		for (int i = ant; i <= 9; i++) {
			r += solve(i, x-1);
		}
		return dp[ant][x] = r;
	}
}

int main() {
	string number;

	cin >> number;
	int n = number[0] - '0';

	i64 r = 0;
	for (int i = 0; i < n; i++) {
		r += solve(i, number.size()-1);
	}

	cout << r << endl;

	return 0;
}
