//Codeforces - QAQ - 894A
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;

	int lv = 0;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == 'Q') {
			for (size_t j = i+1; j < s.size(); j++) {
				if (s[j] == 'A') {
					for (size_t k = j+1; k < s.size(); k++) {
						if (s[k] == 'Q') {
							lv++;
						}
					}
				}
			}
		}
	}

	cout << lv << endl;
	return 0;
}
