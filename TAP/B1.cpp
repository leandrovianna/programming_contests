#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define N 10000

int main() {
	int t;
	double n1;
	double res;
	char str[N];
	char op;

	cin >> t;

	cout << fixed << setprecision(2);

	for (int i = 0; i < t; i++) {
		cin >> n1;
		res = n1;
		cin.getline(str, N);
		for (int j = 0; j < strlen(str); j++) {
			op = str[j];
			switch (op) {
				case '@':
					res *= 3;
					break;
				case '%':
					res += 5;
					break;
				case '#':
					res -= 7;
					break;
			}
		}

		cout << res << endl;
	}

	return 0;
}
