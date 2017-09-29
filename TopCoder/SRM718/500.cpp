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

class InterleavingParenthesisDiv2 
{
	const int N = 60;
	const int MOD = 1e9+7;

    public:
		int countWays(string s1, string s2) {
			int p1[N], p2[N];
			int dp[N][N];

			p1[0] = p2[0] = 0;
			for (int i = 1; i <= s1.size(); i++) {
				p1[i] = p1[i-1] + (s1[i-1] == '(' ? 1 : -1);
			}
			for (int i = 1; i <= s2.size(); i++) {
				p2[i] = p2[i-1] + (s2[i-1] == '(' ? 1 : -1);
			}

			dp[0][0] = 1;
			for (int i = 0; i <= s1.size(); i++) {
				for (int j = 0; j <= s2.size(); j++) {
					if (p1[i] + p2[j] < 0) {
						dp[i][j] = 0;
						continue;
					}
					
					if (i > 0) dp[i][j] += dp[i-1][j];
					if (j > 0) dp[i][j] += dp[i][j-1];

					dp[i][j] %= MOD;
				}
			}

			if (p1[s1.size()] + p2[s2.size()] == 0)
				return dp[s1.size()][s2.size()];
			else
				return 0;
		}
};

int main() {
	ios::sync_with_stdio(false);
		
	InterleavingParenthesisDiv2 *i = new InterleavingParenthesisDiv2();
	cout << i->countWays("(", ")") << endl
		<< i->countWays("(()", "())") << endl;
	return 0;
}
