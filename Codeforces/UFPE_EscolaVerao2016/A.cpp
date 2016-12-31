#include <iostream>
#include <algorithm>
using namespace std;

string p[5][5];
char t[5][5];
string l[25];

void imprimi(char x) {
	int k = 0;	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (t[i][j] == x)
				l[k++] = p[i][j];

	sort(l, l+k);

	for (int i = 0; i < k; i++)
		cout << l[i] << (i != k-1 ? ' ' : '\n');
}

int main() {

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> p[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> t[i][j];

	imprimi('V');
	imprimi('A');
	imprimi('N');
	imprimi('E');
	return 0;
}
