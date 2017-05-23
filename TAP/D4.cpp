#include <iostream>
#include <cctype>
#include <set>
using namespace std;

#define N 5
char table[N][N];

string getsubs(char c1, char c2, char table[][N]) {
	string s;
	int i1, j1, i2, j2;
	c1 = toupper(c1);
	c2 = toupper(c2);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] == c1) {
				i1 = i;
				j1 = j;
			} else if (table[i][j] == c2) {
				i2 = i;
				j2 = j;
			}
		}
	}

	if (i1 == i2) {
		s += table[i1][(j1+1)%N];
		s += table[i2][(j2+1)%N];
	} else if (j1 == j2) {
		s += table[(i1+1)%N][j1];
		s += table[(i2+1)%N][j2];
	} else {
		s += table[i1][j2];
		s += table[i2][j1];
	}

	return s;
}

int main() {
	string key_phase, pretext, text = "";
	set<char> letters;

	getline(cin, key_phase);
	getline(cin, pretext);
	for (int i = 0; i < pretext.size(); i++)
		if (pretext[i] != ' ') text += pretext[i];


	int l = 0, c = 0;
	for (string::iterator it = key_phase.begin(); it != key_phase.end(); ++it) {
		if ('a' <= *it && *it <= 'z') {
			if (letters.find(*it) == letters.end()) {
				letters.insert(*it);
				table[l][c] = toupper(*it);

				c++;
				if (c == N) {
					l++;
					c = 0;
				}
			}
		}
	}

	char ch = 'a';
	int o = c;
	for (int i = l; i < N; i++) {
		for (int j = o; j < N; j++) {
			o = 0;
			while (ch == 'q' || letters.find(ch) != letters.end()) {
				ch++;
			}

			letters.insert(ch);
			table[i][j] = toupper(ch);
			ch++;
		}
	}

	// for (int i = 0; i < N; i++, cout << endl)
	// 	for (int j = 0; j < N; j++)
	// 		cout << table[i][j] << " ";

	string res;
	char c1, c2;

	for (int i = 0; i < text.size(); i+=2) {
		c1 = text[i];
		c2 = (i+1 == text.size()) ? 'x' : text[i+1];
		if (c1 == c2) {
			i--;
			c2 = 'x';
		}

		res += getsubs(c1, c2, table);
	}

	cout << res << endl;
	return 0;
}
