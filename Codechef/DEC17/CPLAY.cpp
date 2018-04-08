//CodeChef - Penalty Shoot-out - DEC17 CPLAY
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	const int N = 10;
	string s;
	bool ta[N], tb[N];

	while (cin >> s) {
		int k = 0, i = 0;
		for (auto &c : s) {
			if (k % 2 == 0) {
				ta[i] = (c == '1');
			} else {
				tb[i] = (c == '1');
				i++;
			}
			k++;
		}

		int pa = 0, pb = 0; //points of teams
		int da = 5, db = 5;
		int shoots = 0;
		for (i = 0; i < 5; i++) {
			if (ta[i]) pa++;
			shoots++;
			da--;

			if (pa - pb > db) {
				cout << "TEAM-A " << shoots << '\n';
				break;
			}

			if (pb - pa > da) {
				cout << "TEAM-B " << shoots << '\n';
				break;
			}

			if (tb[i]) pb++;
			shoots++;
			db--;

			if (pa - pb > db) {
				cout << "TEAM-A " << shoots << '\n';
				break;
			}

			if (pb - pa > da) {
				cout << "TEAM-B " << shoots << '\n';
				break;
			}
		}

		if (i < 5) continue; //already defined a winner

		for (i = 5; i < N; i++) {
			if (ta[i]) pa++;
			shoots++;

			if (tb[i]) pb++;
			shoots++;

			if (pa > pb) {
				cout << "TEAM-A " << shoots << endl;
				break;
			} else if (pb > pa) {
				cout << "TEAM-B " << shoots << endl;
				break;
			}
		}


		if (i == N)
			cout << "TIE\n";
	}
	
	return 0;
}
