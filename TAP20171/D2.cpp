#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int m, x1;
	char c1, c2;
	vector<pair<char, int>> v;
	map<int, int> time, new_time;

	cin >> m;

	while (m-- > 0) {
		cin >> c1 >> x1;
		v.push_back(make_pair(c1, x1));
	}

	v.push_back(make_pair('W', 0)); //add one for loop look for all entries

	for (int i = 1; i < v.size(); i++) {
		c1 = v[i-1].first;
		x1 = v[i-1].second;

		c2 = v[i].first;

		switch (c1) {
			case 'R':
				new_time[x1] = 0;
				if (time.find(x1) == time.end())
					time[x1] = 0;
				break;
			case 'S':
				time[x1] += new_time[x1];
				new_time.erase(new_time.find(x1));
				break;
			case 'W':
				for (auto& imap : new_time)
					imap.second += x1;
		}

		if ((c1 == 'R' || c1 == 'S') 
				&& (c2 == 'R' || c2 == 'S'))
			for (auto& imap : new_time)
				imap.second++;
	}

	for (auto const& imap : time) {
		if (new_time.find(imap.first) != new_time.end()) {
				cout << imap.first << " -1" << endl;
		} else {
			cout << imap.first << " " << imap.second << endl;
		}
	}
	return 0;
}
