#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define N (100)

bool is_attacked(int x, int y, int board[][N], int dim) {
	int i, j;

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			if (board[i][j]) {
				if (i+j == x+y)
					return true;
				if (i-j == x-y)
					return true;
				if (i == x || j == y)
					return true;
			}
		}
	}
	return false;
}

bool n_queens(int board[][N], int n, int dim) {
	int i, j;
	if (n == 0)
		return true;
	else {
		for (i = 0; i < dim; i++) {
			for (j = 0; j < dim; j++) {
				if (is_attacked(i, j, board, dim))
					continue;

				board[i][j] = 1;

				if (n_queens(board, n-1, dim))
					return true;

				board[i][j] = 0;
			}
		}
	}

	return false;
}

int main() {
	int board[N][N], i, j, n;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		memset(board[i], 0, n);

	if (n_queens(board, n, n)) {
		printf("YES\n");

		for (i = 0; i < n; i++, printf("\n"))
			for (j = 0; j < n; j++)
				printf("%d ", board[i][j]);
	} else {
		printf("NO\n");
	}

	return 0;
}
