//Codeforces - Given Lenght and Sum of  Digits... - 489C
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int m, s;

	cin >> m >> s;

	if (s == 0) {
		cout << (m == 1 ? "0 0" : "-1 -1") << endl;
		return 0;
	}

	vector<int> max;
	int acc = s;
	for (int i = 0; i < m; i++) {
		for (int d = 9; d >= (i == 0 ? 1 : 0); d--) {
			if (acc - d >= 0) {
				max.push_back(d);
				acc -= d;
				break;
			}
		}
	}
	if (acc > 0) {
		max.clear();
		max.push_back(-1);
	}

	vector<int> min;
	acc = s;
	for (int i = 0; i < m; i++) {
		for (int d = (i == 0 ? 1 : 0); d < 10; d++) {
			if (acc - d <= 9 * (m - i - 1)) {
				min.push_back(d);
				acc -= d;
				break;
			}
		}
	}

	if (acc > 0) {
		min.clear();
		min.push_back(-1);
	}

	for (auto &x : min) {
		cout << x;
	}
	cout << " ";
	for (auto &x : max) {
		cout << x;
	}
	cout << endl;

	return 0;
}
