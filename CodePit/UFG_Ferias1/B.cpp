#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

int main() {
	string s;
	set<char> letters;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		letters.clear();

		cin.ignore();
		getline(cin, s);

		for (int j = 0; j < s.size(); j++) {
			if ('a' <= s[j] && s[j] <= 'z') 
				letters.insert(s[j]);
		}

		if (letters.size() == 26)
			cout << "frase completa" << endl;
		else if (letters.size() >= 13)
			cout << "frase quase completa" << endl;
		else
			cout << "frase mal elaborada" << endl;
	}
	return 0;
}
