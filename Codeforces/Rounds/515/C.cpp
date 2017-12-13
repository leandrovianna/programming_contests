//Codeforces - Drazil and Factorial - 515C
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a, b(n);
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		b[i] = ch - '0';
	}

	a.clear();

	for (const auto& x : b) {
		switch (x) {
			case 4:
				a.push_back(2);
				a.push_back(2);
				a.push_back(3);
				break;
			case 6:
				a.push_back(3);
				a.push_back(5);
				break;
			case 8:
				a.push_back(2);
				a.push_back(2);
				a.push_back(2);
				a.push_back(7);
				break;
			case 9:
				a.push_back(2);
				a.push_back(3);
				a.push_back(3);
				a.push_back(7);
				break;
			case 1:
			case 0:
				break;
			default:
				a.push_back(x);
		}
	}

	sort(a.begin(), a.end(), greater<int>());

	for (const auto &x : a) {
		cout << x;
	}
	cout << endl;

	return 0;
}
