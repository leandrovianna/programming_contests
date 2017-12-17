//URI - Luzes de Natal - B
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	int64_t x;
	cin >> n;
	while (n--) {
		cin >> x;
		bitset<70> bs(x);
		string s = bs.to_string();

		int k = 0, ah = 0;
		for (const auto &c : s) {
			if (c == '1')
				k++;
			else {
				k = 0;
			}

			ah = max(ah, k);
		}

		cout << ah << endl;
	}
	return 0;
}
