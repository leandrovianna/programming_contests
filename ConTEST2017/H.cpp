#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

#define N 24+1
#define H 7+1

double dp[N][H];

double solve(int n, int h, double p) {
	if (n == 0) {
		if (h >= 0) return dp[n][h] = 1;
	} 

	if (dp[n][h] != 0) return dp[n][h];

	double s = 0;
	for (int i = 0; i <= h; i++) {
		s += p * pow(1 - p, i) * solve(n-1, h-i, p);
	}

	return dp[n][h] = s;
}

int main() {
	int t;
	int n, h;
	double p;

	cin >> t;
	cout << fixed << setprecision(15);

	for (int ti = 1; ti <= t; ti++) {
		cin >> n >> h >> p;

		for (int i = 0; i <= n; i++)
			memset(dp[i], 0, sizeof(dp[i]));

		cout << "Caso " << ti << ": "
			<< solve(n, h, p) << endl;
	}

	return 0;
}
