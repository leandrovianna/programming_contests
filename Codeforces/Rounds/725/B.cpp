#include <iostream>
using namespace std;

int main() {
	long long n;
	char c;

	cin >> n >> c;

	long long s = 0; //seconds
	int r = n % 4;

	s += (n-1) / 4 * 16;

	switch (r) {
		case 0:
		case 2:
			s += 6 + 1; break;
	}

	switch (c) {
		case 'a':
			s += 4; break;
		case 'b':
			s += 5; break;
		case 'c':
			s += 6; break;
		case 'd':
			s += 3; break;
		case 'e':
			s += 2; break;
		case 'f':
			s += 1; break;
	}

	cout << s << endl;
	return 0;
}
