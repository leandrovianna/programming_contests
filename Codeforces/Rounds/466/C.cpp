//Codeforces - Number of Ways - 466C
#include <bits/stdc++.h>
using namespace std;

const int N = 5'000'10;

int main() {
	ios::sync_with_stdio(false);
	int n, v[N], p[N], s[N];
	int total = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		total += v[i];
	}

	if (total % 3 == 0) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += v[i];

			if (sum == total/3) {
				p[i] = 1;
			} else {
				p[i] = 0;
			}
		}

		sum = 0;
		for (int i = n-1; i >= 0; i--) {
			sum += v[i];

			if (sum == total/3) {
				s[i] = sum;
			} else {
				s[i] = 0;
			}
		}
	} else {
		cout << "0\n";
	}

	return 0;
}
