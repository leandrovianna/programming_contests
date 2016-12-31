#include <iostream>
using namespace std;

int mini(int a, int b) {
	return (a <= b) ? a : b;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int da = a / 2;
	int db = b / 3;
	int dc = c / 5;

	cout << mini(da, mini(db, dc)) << endl;
	return 0;
}
