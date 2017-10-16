//Codeforces - Beautiful Year - 271A
#include <bits/stdc++.h>
using namespace std;

bool is_answer(int y) {
	int d = y;
	bool cont[10] = {false};
	bool ans = true;

	while (d) {
		if (cont[d%10]) {
			ans = false;
			break;
		}

		cont[d%10] = true;
		d /= 10;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int year;
	cin >> year;
	year++;
	while (!is_answer(year))
		year++;

	cout << year << endl;
	return 0;
}
