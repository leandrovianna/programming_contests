#include <iostream>
#include <cmath>
using namespace std;

bool is_consonant(char c) {
	return !(c == 'a' || c == 'e' || c == 'o'
				|| c == 'i' || c == 'u');
}

int main() {
	string s, t;
	int diff;
	const char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

	cin >> s;

	for (auto &c : s) {
		t += c;

		if (is_consonant(c)) {
			diff = 100;
			for (int i = 0; i < 5; i++) {
				if (abs(c - vowel[i]) < abs(diff)) {
					diff = c - vowel[i];
				}
			}

			t += (char) c - diff;

			if (c != 'z') {
				diff = 1;
				while (!is_consonant(c+diff)) {
					diff++;
				}
			}
			else
				diff = 0;

			t += (char) c + diff;
		}
	}

	cout << t << endl;
	return 0;
}
