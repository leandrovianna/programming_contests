#include <iostream>
using namespace std;

typedef struct {
	int x, y;
} Foto;

int maxi(int a, int b) {
	return (a >= b) ? a : b;
}

int main() {
	int x, y;
	Foto f1, f2;

	cin >> x >> y;
	cin >> f1.x >> f1.y;
	cin >> f2.x >> f2.y;

	if (f1.x + f2.x <= x && maxi(f1.y, f2.y) <= y) {
		cout << "S" << endl;
	}
	else if (f1.x + f2.y <= x && maxi(f1.y, f2.x) <= y) {
		cout << "S" << endl;
	}
	else if (f1.y + f2.x <= x && maxi(f1.x, f2.y) <= y) {
		cout << "S" << endl;
	}
	else if (f1.y + f2.y <= x && maxi(f1.x, f2.x) <= y) {
		cout << "S" << endl;
	}
	else if (f1.y + f2.y <= y && maxi(f1.x, f2.x) <= x) {
		cout << "S" << endl;
	}
	else if (f1.x + f2.y <= y && maxi(f1.y, f2.x) <= x) {
		cout << "S" << endl;
	}
	else if (f1.y + f2.x <= y && maxi(f1.x, f2.y) <= x) {
		cout << "S" << endl;
	}
	else if (f1.x + f2.x <= y && maxi(f1.y, f2.y) <= x) {
		cout << "S" << endl;
	}
	else
		cout << "N" << endl;
	return 0;
}
