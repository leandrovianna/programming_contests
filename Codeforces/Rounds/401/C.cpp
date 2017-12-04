//Codeforces - Team - 401C
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	size_t need;

	cin >> n >> m;

	need = static_cast<size_t>(n + m);
	
	string output = "";

	if (n > m) {
		output += "0";
		n--;
	}

	while (m > 0) {
		if (m > n && m >= 2) {
			output += "11";
			m -= 2;
		} else {
			output += "1";
			m--;
		}

		if (n > 0) {
			output += "0";
			n--;
		}
	}

	while (n > 0) {
		output += "0";
		n--;
	}

	if (output.find("00") == string::npos
			&& output.find("111") == string::npos) {
		cout << output << endl;
	} else {
		cout << "-1\n";
	}

	return 0;
}
