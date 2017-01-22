#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 1001

int dp[MAX][MAX];

bool solve(int x, vector<int> coins, int qtd) {
	// cout << "solve " << x << " " << qtd << endl;
	if (x == 0 && qtd >= 0)
		return true;
	else if (qtd <= 0 || x < 0)
		return false;
	else if (dp[x][qtd] != -1)
		return dp[x][qtd];
	else {
		for (const int& c : coins) {
			if (solve(x-c, coins, qtd-1)) {
				return (dp[x][qtd] = 1);
			}
		}

		return (dp[x][qtd] = 0);
	}

}

int main() {
	int n, m;
	vector<int> c;

	for (int i = 0; i < MAX; i++)
		memset(dp[i], -1, sizeof(dp[i]));

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		c.push_back(a);
	}

	if (solve(m, c, 9))
		cout << "S" << endl;
	else
		cout << "N" << endl;
	return 0;
}

