#include <iostream>
using namespace std;

int main() {
	int m, d, n;

	cin >> m >> d;
	
	n = m * 100 + d;

	if (n == 218)
		cout << "Special" << endl;
	else if (n < 218)
		cout << "Before" << endl;
	else
		cout << "After" << endl;

	return 0;
}
