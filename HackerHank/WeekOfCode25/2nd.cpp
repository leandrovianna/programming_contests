#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t;
	int k, q, minK;

	cin >> s;
	cin >> t;
	cin >> k;

	q = 0;
	for (auto it = s.begin(), it2 = t.begin();
			it != s.end() && it2 != t.end(); it++, it2++) {
		if (*it == *it2) q++;
		else break;
	}

	minK = (s.length() - q) + (t.length() - q);

	if (k >= s.length() + t.length()
			|| (k >= minK && (k - minK) % 2 == 0))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
