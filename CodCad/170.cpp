#include <iostream>
#include <cstring>
using namespace std;

#define MAX 5001

int dp[MAX][MAX];

int solve(int s, int n2, int n5, int n10, int n20, int n50, int n100) {
	int qtd = n2+n5+n10+n20+n50+n100;

	if (s == 0)
		return 1;
	else if (s < 0)
		return 0;
	else if (dp[s][qtd] != -1)
		return dp[s][qtd];
	else {

		dp[s][qtd] = 0;

		if (n2 > 0)
			dp[s][qtd] += solve(s-2, n2-1, n5, n10, n20, n50, n100);
		
		if (n5 > 0)
			dp[s][qtd] += solve(s-5, n2, n5-1, n10, n20, n50, n100);

		if (n10 > 0)
			dp[s][qtd] += solve(s-10, n2, n5, n10-1, n20, n50, n100);

		if (n20 > 0)
			dp[s][qtd] += solve(s-20, n2, n5, n10, n20-1, n50, n100);

		if (n50 > 0)
			dp[s][qtd] += solve(s-50, n2, n5, n10, n20, n50-1, n100);

		if (n100 > 0)
			dp[s][qtd] += solve(s-100, n2, n5, n10, n20, n50, n100-1);

		cout << s << " " << qtd << " " << dp[s][qtd] << endl;
		return dp[s][qtd];
	}
}

int main() {
	int s, n2, n5, n10, n20, n50, n100;

	cin >> s >> n2 >> n5 >> n10 >> n20 >> n50 >> n100;

	for (int i = 0; i < MAX; i++)
		memset(dp[i], -1, sizeof(dp[i]));

	int n = solve(s, n2, n5, n10, n20, n50, n100);

	cout << n << endl;
	return 0;
}
