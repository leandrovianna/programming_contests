#include <iostream>
using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	const int N = 50;
	string s[N];	
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	int t = s[0].size();

	int acc = 0, p, res = 999999;
	for (int i = 0; i < n; i++) {
		acc = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			int k;
			for (k = 0; k < t; k++) {
				int l;
				for (l = 0; l < t; l++)	{
					if (s[i][l] != s[j][(k+l)%t])
						break;
				}
				if (l == t) {
					acc += k;
					break;
				}
			}
			if (k == t)
				return cout << "-1" << endl, 0;
		}

		res = min(res, acc);
	}

	cout << res << endl;
	return 0;
}
