//TAP20172 - Alphabet - A3
//LIS O(n log n)
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string s;

	cin >> s;
	
	set<char> st;
	auto it = st.begin();
	for (set<char>::size_type i = 0; i < s.size(); i++) {
		if (st.find(s[i]) != st.end()) continue;

		st.insert(s[i]);		
		it = st.find(s[i]);
		if (next(it) != st.end())
			st.erase(next(it));
	}

	cout << 26U - st.size() << endl;

	return 0;
}
