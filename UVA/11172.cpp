#include <iostream>
using namespace std;

int main() {
	int x, y, n;

	cin >> n;
	while (n--) {
		cin >> x >> y;
		cout << ((x < y) ? '<' : ((x == y) ? '=' : '>')) << endl;
	}
	return 0;
}
