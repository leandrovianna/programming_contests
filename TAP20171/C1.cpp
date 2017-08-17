#include <cstdio>
using namespace std;

int main() {
	int n, t;
	char l;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %c", &n, &l);

		for (int k = 0; k < n; k++) {
			for (int j = 0; j < k+1; j++)
				printf("%c", l);
			printf("\n");
			l = (l - 'A' + 1) % 26 + 'A'; 
		}

		if (i != t-1)
			printf("\n");
	}
	return 0;
}
