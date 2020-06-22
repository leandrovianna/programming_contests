#include <stdio.h>

#define N 1000000

int main() {
	int n, a[N], q, l, r, i;
	int sum[N], res;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum[i] = (i != 0) ? sum[i-1] + a[i] : a[i];
	}

	scanf("%d", &q);
	while (q-- > 0) {
		scanf("%d %d", &l, &r);
		l--;
		r--;

		res = (l != 0) ? sum[r] - sum[l-1] : sum[r];
		printf("%d\n", res);
	}
	return 0;
}
