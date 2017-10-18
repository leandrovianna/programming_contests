//Codeforces - Huge Strings - 868D
#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
	const int MAX_LEN = 9;
	string tmp;
	for (int len = 1; len <= MAX_LEN; len++) {
		for (int mask = 0; mask < (1 << len); mask++) {
			tmp = "";
			for (int i = 0; i < len; i++) {
				if (mask & (1 << i)) tmp += '1';
				else tmp += '0';
			}

			// nao encontrei todas as substrings
			// de tamanho len
			// entao a resposta é len - 1
			if (s.find(tmp) == string::npos) return len - 1;
		}
	}

	return MAX_LEN;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	int l, r;
	string s;
	vector<string> vs;
	vector<int> ans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		vs.push_back(s);
		ans.push_back(0);
	}

	cin >> m;
	int tmp;
	const int LIMIT = 2000;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		l--;
		r--;
		s = vs[l] + vs[r];

		if (s.size() > LIMIT)
			vs.push_back(s.substr(0, LIMIT/2) + s.substr(s.size()-LIMIT/2, LIMIT/2));
		else
			vs.push_back(s);

		tmp = max( {ans[l], ans[r], solve(s)} );
		ans.push_back(tmp);
		cout << tmp << endl;
	}
	
	return 0;
}
