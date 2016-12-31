//https://www.urionlinejudge.com.br/judge/pt/problems/view/1192
#include <stdio.h>

int main() {
	int n, i, d1, d2;
	char c;

	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d%c%d", &d1, &c, &d2);
		
		if (d1 == d2)
			printf("%d\n", d1 * d2);
		else if (c >= 'A' && c <= 'Z')
			printf("%d\n", d2 - d1);
		else if (c >= 'a' && c <= 'z')
			printf("%d\n", d1 + d2);
	}
	return 0;
}
