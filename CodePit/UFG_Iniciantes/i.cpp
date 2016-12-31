#include <iostream>
using namespace std;

const int N = 100, M = 100;

void dfs(int t[][M], const int i, const int j, const int n, const int m) {
	int top = (i != 0 && t[i-1][j] == 1) ? 1 : 0;
	int left = (j != 0 && t[i][j-1] == 1) ? 1 : 0;
	int bottom = (i != n-1 && t[i+1][j] == 1) ? 1 : 0;
	int right = (j != m-1 && t[i][j+1] == 1) ? 1 : 0;

	if (top) {
		t[i-1][j] = t[i][j];
		dfs(t, i-1, j, n, m);
	}

	if (left) { 
		t[i][j-1] = t[i][j];
		dfs(t, i, j-1	, n, m);
		
	}

	if (bottom) { 
		t[i+1][j] = t[i][j];
		dfs(t, i+1, j, n, m);
	}

	if (right) {
		t[i][j+1] = t[i][j];
		dfs(t, i, j+1, n, m);	
	}

}



int count(int t[][M], const int n, const int m) {
	int nlabels = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (t[i][j]) {
				if (t[i][j] == 1)
					t[i][j] = ++nlabels;

				dfs(t, i, j, n, m);
			}
		}
	}

	int nc = 0;
	int labels[N*M/2] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (t[i][j] && !labels[t[i][j]]) {
				labels[t[i][j]] = 1;
				nc++;
			}
		}
	}

	return nc;
}


int main() {
	int tab[N][M], n, m, c, l, k, nc1, nc2;
	char ch;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> ch;
			tab[i][j] = (ch == '#') ? 1 : 0;

		}

	nc1 = count(tab, n, m);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> l >> c;
		tab[--l][--c] = 0;
	}
	
	nc2 = count(tab, n, m);
	cout << nc1 - nc2 << endl;
	return 0;
}
