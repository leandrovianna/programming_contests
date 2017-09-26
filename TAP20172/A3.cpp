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
	string s;
	const int N = 60;
	int v[N], dp[N];

	cin >> s;
	int k = 0;
	for (auto& c : s) {
		v[k] = c - 'a';
		dp[k] = 1;
		k++;
	}

	int r = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		r = max(r, dp[i]);
	}

	cout << (26 - r) << endl;

	return 0;
}
