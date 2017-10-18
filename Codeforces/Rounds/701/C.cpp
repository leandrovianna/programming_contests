#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	string str;
	set<char> letters;

	cin >> n;
	cin >> str;

	for (auto &c : str) {
		letters.insert(c);
	}
	
	vector<int> len(str.size());
	
	for (auto &c : letters) {
		int last = -1;
		for (size_t i = 0; i < str.size(); i++) {
			if (str[i] == c) last = (int) i;

			if (last == -1) len[i] = 1e9;
			else len[i] = max(len[i], (int) i - last + 1);
		}
	}

	cout << *min_element(len.begin(), len.end()) << endl;

	return 0;
}
