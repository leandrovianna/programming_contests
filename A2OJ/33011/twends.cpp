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

const int N = 1010;
const int NI = 1e7;
int v[N], dp[N][N];

int solve(int i, int j) {
	if (dp[i][j] != NI) return dp[i][j];
	if (i > j) return 0;

	int x = (v[i] - max(v[i+1], v[j])) + (v[i+1] >= v[j] ? solve(i+2, j) : solve(i+1, j-1));
	int y = (v[j] - max(v[i], v[j-1])) + (v[i] >= v[j-1] ? solve(i+1, j-1) : solve(i, j-2));
	return dp[i][j] = max(x, y);
}

int main() {
	ios::sync_with_stdio(false);
	int n, k = 1;

	while (cin >> n, n) {
		for (int i = 0; i < n; i++) cin >> v[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = NI;

		cout << "In game " << k++ << ", the greedy strategy might lose by as many as " 
			<< solve(0, n-1) << " points.\n";
	}
	return 0;
}
