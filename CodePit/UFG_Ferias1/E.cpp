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

const int N = 100;

int dp[N];

int main() {
	int n, v[N], c, r;

	while (cin >> n) {
		cin >> c;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			v[i] = v[i] - c;
		}

		dp[0] = max(v[0], 0);
		for (int i = 1; i < n; i++) {
			dp[i] = max(v[i], dp[i-1] + v[i]);
		}

		r = 0;
		for (int i = 0; i < n; i++)
			r = max(r, dp[i]);

		cout << r << endl;
	}
	return 0;
}
