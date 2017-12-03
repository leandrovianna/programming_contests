//Codeforces - Number of Ways - 466C
#include <bits/stdc++.h>
using namespace std;

const int N = 5'000'10;

int main() {
	ios::sync_with_stdio(false);
	int n, v[N], p[N];
	int64_t s[N];
	int64_t total = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		total += v[i];
		p[i] = 0;
		s[i] = 0;
	}

	if (total % 3 == 0) {
		int64_t sum = 0;
		for (int i = 0; i < n; i++) {
			sum += static_cast<int64_t>(v[i]);

			if (sum == total/3) {
				p[i] = 1;
			} else {
				p[i] = 0;
			}

		}

		s[0] = p[0];
		for (int i = 1; i < n; i++) {
			s[i] = s[i-1] + p[i];
		}
		
		int64_t ans = 0;
		sum = 0;
		for (int i = n-1; i >= 2; i--) {
			sum += v[i];

			if (sum == total/3) {
				ans += s[i-2];
			}
		}

		cout << ans << endl;

	} else {
		cout << "0\n";
	}

	return 0;
}
