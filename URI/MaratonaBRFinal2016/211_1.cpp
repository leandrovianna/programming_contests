#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int v[4];

	for (int i = 0; i < 4; i++)
		cin >> v[i];

	cout << abs((v[0] + v[3]) - (v[1] + v[2])) << endl;
	return 0;
}
