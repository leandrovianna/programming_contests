//TAP20172 - Hipercampo - H5
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, xa, xb;
vector<pair<int, int> > points;

const double EPS = 1e-9;

double area(int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs( (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// verify if j is inner triangle ABi
bool inside(int i, int j) {
	int xi = points[i].second;
	int yi = points[i].first;
	int xj = points[j].second;
	int yj = points[j].first;

	double a = area(xa, 0, xb, 0, xi, yi);
	double a1 = area(xa, 0, xb, 0, xj, yj);
	double a2 = area(xa, 0, xi, yi, xj, yj);
	double a3 = area(xb, 0, xi, yi, xj, yj);
	
	return fabs(a - (a1 + a2 + a3)) < EPS;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> xa >> xb;
	for (int i = 0; i < n; i++) {
		auto p = pair<int,int>{};
		cin >> p.second >> p.first;
		points.push_back(p);
	}

	sort(points.begin(), points.end());

	int dp[N];
	int r = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (inside(i, j)) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		r = max(dp[i], r);
	}

	cout << r << endl;
	return 0;
}
