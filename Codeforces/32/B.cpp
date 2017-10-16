//Codeforces - Borze - 32B
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string str, ans = "";
	cin >> str;
	for (auto it = str.begin(); it != str.end(); it++) {
		if (*it == '.')
			ans += '0';
		else if (*next(it) == '.')
			ans += '1', it++;
		else
			ans += '2', it++;
	}

	cout << ans << endl;
	return 0;
}
