//https://www.urionlinejudge.com.br/judge/pt/problems/view/1068
#include <stdio.h>

#define N 1000+1

void corrector(char []);

int main() {
	char s[N];	

	while (scanf("%s", s) != EOF) {
		corrector(s);
	}
	return 0;
}

void corrector(char s[]) {
	int i = 0, p = 0;

	while (s[i]) {
		if (s[i] == '(')
			p++;
		else if (s[i] == ')') {
			if (p == 0) {
				printf("incorrect\n");
				return ;
			}

			p--;
		}
		i++;
	}

	if (p != 0)
		printf("incorrect\n");
	else
		printf("correct\n");
}
