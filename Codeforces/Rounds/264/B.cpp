//Codeforces - Good Sequences - 264B
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int dp[N];

int main() {
	ios::sync_with_stdio(false);
	int n;
	vector<int> p;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int a = arr[i];
		for (int pi = 2; pi * pi <= a; pi++) {
			if (a % pi) continue;

			p.push_back(pi);
			while (a % pi == 0)
				a /= pi;
		}
		if(a > 1)
			p.push_back(a);
		int r = 0;
		for (auto &pi : p) {
			r = max(r, dp[pi]);
		}

		for (auto &pi : p) {
			dp[pi] = r + 1;
		}
		p.clear();
	}
	
	cout << max(1,*max_element(dp,dp+N)) << endl;
	
	return 0;
}
