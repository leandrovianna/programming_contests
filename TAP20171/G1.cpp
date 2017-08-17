#include <iostream>
#include <cstring>
using namespace std;

#define N (100+1)

int main() {
	int t;
	char s[N];

	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		cin >> s;
		cout << s[0];
		for (int i = 1; i < strlen(s); i++) {
			if (s[i] != s[i-1])
				cout << s[i];
		}
		cout << endl;
	}
	return 0;
}
