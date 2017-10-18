#include <iostream>
#include <cstring>
using namespace std;

#define N 1000100
#define M (1000000007)

int dp[N];

//Equation to solve:
//Let A(n) be the moves for substring aa...b with n 'a's
//A(n) = n + Sum(Ai)(1 <= i <= n-1)
//Can be reduce to
//A(n) = A(n-1) + A(n-1) + 1 = 2 * A(n-1) + 1
//where A(1) = 1

int solve(int n) {
	if (dp[n] != -1)
		return dp[n];
	else {
		return dp[n] = (solve(n-1) % M + solve(n-1) % M + 1) % M;
	}
}

int main() {
	int x, res;
	char c;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	x = res = 0;
	while (cin >> c) {
		if (c == 'a') x++;
		else if (c == 'b') {
			res = (res % M + solve(x) % M) % M;
		}
	}

	cout << res << endl;

	return 0;
}
