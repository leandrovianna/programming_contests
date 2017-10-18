#include <iostream>
using namespace std;

int main() {
	int n;	
	char ant;
	string s;

	cin >> n;


	for (int i = 0; i < n; i++) {
		if (i > 1) ant = s[i-2];
		else ant = 'a';

		if ('a' != ant) s += 'a';
		else if ('b' != ant) s += 'b';
		else if ('c' != ant) s += 'c';
	}

	cout << s << endl;
	return 0;
}
