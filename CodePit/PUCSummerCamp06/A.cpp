//CodePit - Ilya and Escalator - A
#include <bits/stdc++.h>
using namespace std;

const int N = 2010, T = N;

int n, t;
double p;
double dp[N][T];
int used[N][T], vis = 1;

double solve(int i, int j) {
	if (i == n) return n;
	if (j == t) return i;

	double &ans = dp[i][j];

	if (used[i][j] == vis) return ans;
	used[i][j] = vis;

	ans = p * solve(i+1, j+1) + solve(i, j+1) * (1 - p);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> p >> t;

	cout << fixed << setprecision(10)
		<< solve(0, 0) << endl;

	return 0;
}
