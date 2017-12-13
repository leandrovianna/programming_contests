//CodeChef - Chef and Universe - CHEFUNI
//20 points
#include <bits/stdc++.h>
using namespace std;

int t, x, y, z, a, b, c;
const int N = 110, INF = 1'000'000'000;
int dp[N][N][N];
int used[N][N][N], vis = 0;

int solve(int _x, int _y, int _z) {
	if (_x > x || _y > y || _z > z)
		return INF;

	if (x == _x && y == _y && z == _z) {
		return 0;
	}

	int &ans = dp[_x][_y][_z];

	if (used[_x][_y][_z] == vis)
		return ans;

	used[_x][_y][_z] = vis;

	ans = a + solve(_x+1, _y, _z);
	ans = min(ans, a + solve(_x, _y+1, _z));
	ans = min(ans, a + solve(_x, _y, _z+1));
	ans = min(ans, b + solve(_x+1, _y+1, _z));
	ans = min(ans, b + solve(_x, _y+1, _z+1));
	ans = min(ans, b + solve(_x+1, _y, _z+1));
	ans = min(ans, c + solve(_x+1, _y+1, _z+1));

	return ans;
}

int qA, qB, qC;
void flow(int _x, int _y, int _z) {
	int &ans = dp[_x][_y][_z];

	if (ans == a + dp[_x+1][_y][_z])
		flow(_x+1, _y, _z), qA++;
	else if (ans == a + dp[_x][_y+1][_z])
		flow(_x, _y+1, _z), qA++;
	else if (ans == a + dp[_x][_y][_z+1])
		flow(_x, _y, _z+1), qA++;
	else if (ans == b + dp[_x+1][_y+1][_z])
		flow(_x+1, _y+1, _z), qB++;
	else if (ans == b + dp[_x][_y+1][_z+1])
		flow(_x, _y+1, _z+1), qB++;
	else if (ans == b + dp[_x+1][_y][_z+1])
		flow(_x+1, _y, _z+1), qB++;
	else if (ans == c + dp[_x+1][_y+1][_z+1])
		flow(_x+1, _y+1, _z+1), qC++;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> x >> y >> z >> a >> b >> c;
		vis++;
		cout << solve(0, 0, 0) << endl;
		qA = qB = qC = 0;
		flow(0, 0, 0);
		// cout << qA << " " << qB << " " << qC << endl;
	}

	return 0;
}
