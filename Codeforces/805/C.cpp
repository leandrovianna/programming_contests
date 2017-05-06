#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	int r = (n / 2);
	if (n % 2 == 0) r--;

	cout << r << endl;
	return 0;
}
