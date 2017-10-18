//Codeforces - Lights Out - 275A
#include <bits/stdc++.h>
using namespace std;

// const int I[] = {-1, -1, -1, +0, +0, +1, +1, +1};
// const int J[] = {-1, +0, +1, -1, +1, -1, +0, +1};
const int I[] = {-1, +0, +1, +0};
const int J[] = {+0, +1, +0, -1};
int grid[3][3];
void apply(int i, int j) {
	grid[i][j] = !grid[i][j];
	for (int k = 0; k < 4; k++) {
		int x = i + I[k];
		int y = j + J[k];
		if (0 <= x && x < 3 && 0 <= y && y < 3)
			grid[x][y] = !grid[x][y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	int x;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			cin >> x;
			if (x % 2)
				apply(i, j);
		}


	for (int i = 0; i < 3; i++, cout << endl)
		for (int j = 0; j < 3; j++)
			cout << !grid[i][j];
	
	return 0;
}
