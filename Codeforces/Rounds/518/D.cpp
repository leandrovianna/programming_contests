//Codeforces - Ilya and Escalator - 518B Div2
#include <iostream>
#include <iomanip>
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

const int N = 2010;
const int T = 2010;

double p;
int n;
double dp[N][T];

double solve(int t, int x) {
	if (t == 0) return x;
	if (x >= n) return n;
	if (dp[x][t] != -1) return dp[x][t];
	
	dp[x][t] = p * solve(t-1, x+1) + (1-p) * solve(t-1, x);
	return dp[x][t];
}

int main() {
	int t;

	cin >> n >> p >> t;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= t; j++) {
			dp[i][j] = -1;
		}

	cout << fixed << setprecision(9) << solve(t, 0) << endl;
	return 0;
}
