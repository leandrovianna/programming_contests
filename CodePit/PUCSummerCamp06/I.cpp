//CodePit - Rent yout airplane and make money - I
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

struct order {
	int st, d, p;
	bool operator< (order other) {
		return this->st < other.st
			|| (this->st == other.st && this->d < other.d);
	}
};

vector<order> orders(N);

int n, max_time;

const int M = 1000010;
int dp[M];
int used[M], vis = 1;

int solve(int t) {
	if (t > max_time)
		return 0;

	int &ans = dp[t];
	if (used[t] == vis)
		return ans;
	used[t] = vis;

	ans = solve(t+1);

	order ord = {t, 0, 0};
	vector<order>::iterator it = lower_bound(orders.begin(), orders.begin()+n, ord);

	if (it != orders.end()) {
		for (; it != orders.end() && it->st == t; it++) {
			ans = max(ans, solve(it->st + it->d) + it->p);
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int tests;

	cin >> tests;
	while (tests--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> orders[i].st
				>> orders[i].d
				>> orders[i].p;

			max_time = max(max_time, orders[i].st);
		}

		sort(orders.begin(), orders.begin() + n);
		cout << solve(0) << endl;
		vis++;
	}

	return 0;
}
