#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	int n;

	cin >> n;

	for (int ni = 0; ni < n; ni++) {
		cin >> s;
		if (next_permutation(s.begin(), s.end())) {
			cout << s << endl;
		}
		else {
			cout << "USELESS" << endl;
		}
	}
	return 0;
}
