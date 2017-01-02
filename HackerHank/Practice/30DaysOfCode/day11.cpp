#include <iostream>
using namespace std;

int main() {
	const int N = 6, M = 16;
	int a[N][N], k, high;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];

	k = 0;
	high = -100000;
	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < N-2; j++) {
			high = max(a[i][j] + a[i][j+1] + a[i][j+2]
				+ a[i+1][j+1] + a[i+2][j] + a[i+2][j+1]
				+ a[i+2][j+2], high);
		}
	}


	cout << high << endl;
	return 0;
}
