//Upsolving
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

const int M = 1e3+10;
const int V = 1e5+10;

int dp[V];


int main() {
	int v, m, moeda;

	memset(dp, 0, sizeof(dp));

	cin >> v >> m;

	dp[0] = 1; //sempre pagamos 0 reais
	for (int i = 0; i < m; i++) {
		cin >> moeda;

		for (int vi = V-1; vi >= 0; vi--) {
			if (dp[vi] && vi + moeda < V) dp[vi + moeda] = 1;
		}
	}


	if (dp[v])
		cout << "S" << endl;
	else
		cout << "N" << endl;

	return 0;
}
