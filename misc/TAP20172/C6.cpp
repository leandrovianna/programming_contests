#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	size_t k;
	map<string, vector<string> > mp;
	string name, str, line;
	set<pair<string, string> > setans;
	
	cin >> n;
	cin.ignore();
	k = 0;

	for (int i = 0; i < n; i++) {
		getline(cin, line);
		
		istringstream ss(line);

		ss >> name;
		name.pop_back();
		while (ss >> str) {
			mp[name].push_back(str);
		}

		k = max(k, mp[name].size());
	}

	for (auto& p : mp) {
		int j = k-1;
		string ans = "";
		for (auto it = p.second.rbegin(); it != p.second.rend(); it++) {
			//cout << *it << endl;
			if(*it == "class")
				continue;

			//int64_t aux = (1LL << j);
			j--;
			if (*it == "upper") ans += "1";
			if (*it == "middle") ans += "2";
			if (*it == "lower") ans += "3";
			//cout << ans << endl;
		}

		for (; j >= 0; j--)
			ans += "2";

		setans.insert(make_pair(ans, p.first));
	}

	for (auto it = setans.begin(); it != setans.end(); it++) {
		//cout << it->first << endl;
		cout << it->second << endl;
	}

	return 0;
}
