//Accepted
#include <iostream>
using namespace std;

int substr(string s1, string s2, int i, int j) {
	int x = 1;
	while (i+x < s1.size() && j+x < s2.size()) {
		if (s1[i+x] == s2[j+x])
			x++;
		else
			break;
	}
	return x;
}

int main() {
	string s1, s2;	
	int qtd;

	while (getline(cin, s1) && getline(cin, s2)) {
		qtd = 0;
		for (int i = 0; i < s1.size(); i++) {
			for (int j = 0; j < s2.size(); j++) {
				if (s1[i] == s2[j])
					qtd = max(qtd, substr(s1, s2, i, j));
			}
		}

		cout << qtd << endl;
	}
	return 0;
}
