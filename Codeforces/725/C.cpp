#include <iostream>
using namespace std;

int main() {
	const int N = 28, P = 2, M = 13;
	char s[N], m[P][M];	
	int p1, p2;
	
	cin >> s;

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (s[i] == s[j]) {
				p1 = i;
				p2 = j;
				break;
			}
		}
	}

	if (p1 - 1 >= p2 - 2) {
		cout << "Impossible" << endl;
	} else {

		m[1][0] = s[N-2];
		m[1][1] = s[0];

		int pos;
		for (int i = 1; i < p1; i++) {
			m[1][1+i] = s[i];
			pos = 1+i;
		}

		for (int i = N-3; i >= p2; i--) {
			m[0][N-3-i] = s[i];
		}

		int pos2;
		for (int i = 1; pos+i < M; i++) {
			m[0][pos+i] = s[p1+i];
			pos2 = p1+i;
		}

		for (int i = 1; pos+i < M; i++) {
			m[1][13-i] = s[pos2+i];
		}

		for (int i = 0; i < P; i++) {
			for (int j = 0; j < M; j++) {
				cout << m[i][j];
			} cout << endl;
		}
	}

	return 0;
}
