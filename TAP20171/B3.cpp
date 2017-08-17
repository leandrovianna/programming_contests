#include <iostream>
using namespace std;

const int N = 3;

bool isSorted(int *v) {
	int tipo[N], t = 0;
	for (int i = 1; i < N; i++) {
		if (v[i-1] > v[i])
			tipo[t++] = 1;
		else if (v[i-1] < v[i])
			tipo[t++] = 2;

	}

	for (int i = 1; i < t; i++) {
		if (tipo[i-1] != tipo[i])
			return false;
	}

	return true;
}

int main() {
	int **m;

	m = new int*[N];
	for (int i = 0; i < N; i++) {
		m[i] = new int[N];
		for (int j = 0; j < N; j++)
			cin >> m[i][j];
	}
	

	for (int i = 0; i < N; i++) {
		if (!isSorted(m[i])) {
			int *t = m[i];
			m[i] = m[N-1];
			m[N-1] = t;
		}
	}

	for (int i = 0; i < N; i++, cout << endl) {
		for (int j = 0; j < N; j++) {
			cout << m[i][j];
			if (j != N-1)
				cout << " ";
		}
	}

	delete m;

	return 0;
}
