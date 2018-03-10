//CodePit - Minha Camiseta Me Serve - E
#include <bits/stdc++.h>
using namespace std;

int n, sz, lim;
const int M = 40, P = 10;
pair<string, string> v[M];
bool dp[M][P][P][P][P][P][P];
int used[M][P][P][P][P][P][P], vis = 1;

bool bt(int i, int xxl, int xl, int l, int m, int s, int xs) {
	// cout << i << endl;
	if (i == sz)
		return (xxl + xl + l + m + s + xs) <= n;

	bool &ans = dp[i][xxl][xl][l][m][s][xs];

	if (used[i][xxl][xl][l][m][s][xs] == vis)
		return ans;

	used[i][xxl][xl][l][m][s][xs] = vis;

	ans = false;

	string str = v[i].first;

	if (str == "XXL" && xxl < lim)
		ans |= bt(i+1, xxl+1, xl, l, m, s, xs);
	else if (str == "XL" && xl < lim)
		ans |= bt(i+1, xxl, xl+1, l, m, s, xs);
	else if (str == "L" && l < lim)
		ans |= bt(i+1, xxl, xl, l+1, m, s, xs);
	else if (str == "M" && m < lim)
		ans |= bt(i+1, xxl, xl, l, m+1, s, xs);
	else if (str == "S" && s < lim)
		ans |= bt(i+1, xxl, xl, l, m, s+1, xs);
	else if (str == "XS" && xs < lim)
		ans |= bt(i+1, xxl, xl, l, m, s, xs+1);

	str = v[i].second;
	if (str == "XXL" && xxl < lim)
		ans |= bt(i+1, xxl+1, xl, l, m, s, xs);
	else if (str == "XL" && xl < lim)
		ans |= bt(i+1, xxl, xl+1, l, m, s, xs);
	else if (str == "L" && l < lim)
		ans |= bt(i+1, xxl, xl, l+1, m, s, xs);
	else if (str == "M" && m < lim)
		ans |= bt(i+1, xxl, xl, l, m+1, s, xs);
	else if (str == "S" && s < lim)
		ans |= bt(i+1, xxl, xl, l, m, s+1, xs);
	else if (str == "XS" && xs < lim)
		ans |= bt(i+1, xxl, xl, l, m, s, xs+1);

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> sz;

		for (int i = 0; i < sz; i++) {
			cin >> v[i].first >> v[i].second;
		}

		lim = n / 6;

		cout << (bt(0, 0, 0, 0, 0, 0, 0) ? "YES" : "NO") << endl;
		vis++;
	}
	return 0;
}
