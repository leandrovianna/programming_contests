#include <iostream>
using namespace std;

int main() {
	int k, r;
	int s;

	cin >> k >> r;

	for (int i = 1; i < 10; i++) {
		s = i * k;
		if (s % 10 == r || s % 10 == 0) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
