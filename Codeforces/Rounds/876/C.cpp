//Judge - Problem Name - Problem ID
#include <bits/stdc++.h>
using namespace std;

int sum_dig(int k) {
	int acc = k, d;

	for (int exp = 1; k/exp > 0; exp *= 10) {
		d = (k / exp) % 10;
		acc += d;
	}

	return acc;
}

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	vector<int> xs;

	cin >> n;
	for (int i = max(0,n-100); i <= n; i++) {
		if (sum_dig(i) == n) {
			xs.push_back(i);
		}
	}

	cout << xs.size() << endl;
	for (auto it = xs.begin(); it != xs.end(); it++)
		cout << *it << " \n"[it == prev(xs.end())];

	return 0;
}
