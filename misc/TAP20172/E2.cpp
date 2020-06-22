#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;


int main() {
	ios::sync_with_stdio(false);
	string s;
	map<char, int> chars;

	cin >> s;
	for (auto& c : s) {
		if (chars.find(c) == chars.end()) chars[c] = 1;
		else chars[c]++;
	}

	int lowest;
	char ch;
	int changes = 0;
	while (chars.size() > 2) {
		lowest = 1e9;

		for (auto& p : chars) {
			if (lowest > p.second)
				lowest = p.second, ch = p.first;
		}

		changes += lowest;
		chars.erase(ch);
		// cout << "remove " << ch << endl;
	}

	cout << changes << endl;
	return 0;
}
