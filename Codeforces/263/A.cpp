#include <iostream>
using namespace std;

int main() {
	const int N = 5;
	int posi, posj, a;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			if (a == 1) {
				posi = i+1;
				posj = j+1;
			}
		}
	}

	cout << abs(posj - 3) + abs(posi - 3) << endl;

	return 0;
}
