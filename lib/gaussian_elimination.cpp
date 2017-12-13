#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100

struct AugmentedMatrix {
	double mat[MAX_N][MAX_N + 1];
};
struct ColumnVector {
	double vec[MAX_N];
};

ColumnVector elimination(int n, AugmentedMatrix aug) {
	ColumnVector x;

	for (int j = 0, lgst; j < n-1; j++) {
		// find the largest value of column j
		lgst = j;
		for (int i = j + 1; i < n; i++) {
			if (fabs(aug.mat[i][j]) > fabs(aug.mat[lgst][j]))
				lgst = i;
		}

		// change to first row of elimination the row
		// with largest value

		for (int k = j; k < n; k++) {
			swap(aug.mat[j][k], aug.mat[lgst][k]);
		}

		// elimination phase
		for (int i = j + 1; i < n; i++) {
			for (int k = n; k >= j; k--) {
				aug.mat[i][k] -= aug.mat[i][j] * aug.mat[j][k] / aug.mat[j][j];
			}
		}
	}

	for (int j = n-1; j >= 0; j--) {
		double t = 0.0;
		for (int k = j+1; k < n; k++)
			t += aug.mat[j][k] * x.vec[k]; //back substitution
		x.vec[j] = (aug.mat[j][n] - t) / aug.mat[j][j];
	}

	return x;
}

int main() {
	return 0;
}
