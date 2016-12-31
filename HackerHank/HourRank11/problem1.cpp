#include <iostream>
using namespace std;

long counter (long t);

int main() {
	long t;

	cin >> t;

	cout << counter(t) << endl;
	return 0;
}

long counter (long t) {
	long initial = 1, circle = 3;

	while (initial + circle <= t) {
		initial += circle;
		circle *= 2;
	}

	return circle - (t - initial);
}
