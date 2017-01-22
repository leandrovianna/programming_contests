#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 1001

int dp[MAX];

bool solve(int x, vector<int> coins) {
	if (x == 0)
		return true;
	else if (x < 0)
		return false;
	else if (dp[x] != -1)
		return dp[x];
	else {
		for (const int& c : coins) {
			if (solve(x-c, coins)) {
				return dp[x] = true;
			}
		}

		return dp[x] = false;
	}
}

int main() {
	int n, m;
	vector<int> c;

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		c.push_back(a);
	}

	if (solve(m, c))
		cout << "S" << endl;
	else
		cout << "N" << endl;
	return 0;
}

