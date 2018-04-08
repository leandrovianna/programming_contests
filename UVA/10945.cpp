#include <iostream>
#include <cctype>
using namespace std;

int main() {
	string s, sout;
	bool palin;

	while (getline(cin, s) && s != "DONE") {
		sout = "";
		for (int i = 0; i < s.size(); i++) {
			s[i] = tolower(s[i]);
			if ('a' <= s[i] && s[i] <= 'z')
				sout += s[i];
		}

		palin = true;
		for (int i = 0; i < sout.size()/2; i++) {
			if (sout[i] != sout[sout.size()-i-1])
				palin = false;
		}

		if (palin) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}
	return 0;
}
