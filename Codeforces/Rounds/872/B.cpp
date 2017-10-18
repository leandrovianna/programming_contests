//Codeforces -  Maximum of Maximums of Minimums - 872B
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, k, x;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> x, v.push_back(x);

	int ans = v.front();
	if (k == 1)
		ans = *min_element(v.begin(), v.end());
	else if (k == 2)
		ans = max(v.front(), v.back());
	else
		ans = *max_element(v.begin(), v.end());

	cout << ans << endl;
	return 0;
}
