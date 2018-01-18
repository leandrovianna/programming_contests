//Codeforces - Shockers - 907C Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	char ch;
	string str;

	cin >> n;

	set<char> possible;
	for (char c = 'a'; c <= 'z'; c++) {
		possible.insert(c);
	}

	bool flag = false;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> ch;

		if (i == n-1) {
			cin >> ch;
			continue;
		}

		if (flag && (ch == '!' || ch == '?'))
			ans++;

		if (ch == '!') {
			cin >> str;
			set<char> tmp;
			for (const auto &c : str) {
				tmp.insert(c);
			}
			set<char> new_possible;
			for (const auto &c : possible) {
				if (tmp.count(c) > 0)
					new_possible.insert(c);
			}
			possible = new_possible;

		} else if (ch == '.') {
			cin >> str;
			for (const auto &c : str) {
				possible.erase(c);
			}
		} else if (i != n-1 && ch == '?') {
			cin >> ch;

			possible.erase(ch);
		}

		if (possible.size() == 1)
			flag = true;
	}

	cout << ans << endl;

	return 0;
}
