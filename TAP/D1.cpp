#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 100000

bool compara(pair<int, int> a, pair<int, int> b) {
	return (a.second - a.first < b.second - b.first);
}

int main() {
	char str[N];
	bool is_palin;
	vector<pair<int, int> > res;
	set<char> letters;
	
	while (cin >> str) {
		res.clear();
		letters.clear();

		for (unsigned i = 0; i < strlen(str); i++) {
			for (unsigned j = i; j < strlen(str); j++) {

				if (j == i) {
					if (letters.find(str[i]) == letters.end()) {
						res.push_back(make_pair(i, j));
						letters.insert(str[i]);
					}
					continue;
				}

				is_palin = true;
				for (unsigned k = i, l = j;
						k < l; k++, l--) {
					if (str[k] != str[l]) {
						is_palin = false;
						break;
					}
				}
				
				if (is_palin) {
					res.push_back(make_pair(i, j));
				}
			}
		}

		sort(res.begin(), res.end(), compara);

		cout << res.size() << " - ";

		for (size_t i = 0; i < res.size(); i++) {
			cout << "\"";
			for (int k = res[i].first; k <= res[i].second; k++)
				cout << str[k];
			cout << "\"";

			if (i != res.size()-1)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}
