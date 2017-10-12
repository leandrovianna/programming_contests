#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, x;
	vector<int> prob;
	priority_queue<int, vector<int>, greater<int>> q;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> x, prob.push_back(x);

	// read k problems
	for (int i = 0; i < k; i++)
		q.push(prob[i]);

	int t = 0; // time of contest
	int64_t penalty = 0;
	while (!q.empty()) {
		x = q.top(); // choose a problem to solve
		q.pop();
		t += x; // solve problem
		penalty += (int64_t)t; // add submit time to penalty

		// read one more problem
		if (k < n) q.push(prob[k++]);
	}

	cout << penalty << endl;

	return 0;
}
