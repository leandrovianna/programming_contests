#include <iostream>
using namespace std;

int main() {
	int q, a, b, d;

	cin >> q;
	for (int qi = 0; qi < q; qi++) {
		cin >> a >> b >> d;

		int max = (a > b) ? a : b;
		int min = (a < b) ? a : b;

		if (d == 0) {
			cout << 0 << endl;
		} else if (max == d) {
			cout << 1 << endl;
		} else if (max > d) {
			cout << 2 << endl;
		} else {
			int steps = 0;
			int e, r = 1;
			while (r != 0) {
				e = d / max;
				r = d % max;

				if (r == 0)
					steps += e;
				else if (r == min)
					steps += e + 1;
				else if (r < max)
					cout << e + 2 << endl;
			}
		}
	}
	return 0;
}
