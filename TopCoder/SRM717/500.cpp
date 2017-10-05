#include <bits/stdc++.h>
using namespace std;

class LexmaxReplace {
	public:
		string get(string s, string t) {
			sort(t.begin(), t.end(), greater<char>());
			
			int k = 0;
			for (auto &c : s) {
				if (k < t.size() && c < t[k]) {
					c = t[k];
					k++;
				}
			}
			
			return s;
		}
};
