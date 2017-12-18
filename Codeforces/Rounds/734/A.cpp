//Codeforces - Anton and Danik - 734A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	char ch;
	int n, danik = 0, anton = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		if (ch == 'D')
			danik++;
		else
			anton++;
	}

	if (danik > anton)
		cout << "Danik\n";
	else if (danik < anton)
		cout << "Anton\n";
	else
		cout << "Friendship\n";

	return 0;
}
