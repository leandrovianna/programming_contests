#include <iostream>
using namespace std;

int main() {
	const int N = 200001;
	char s[N];
	int n, qtd = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	if (s[0] == '<') {
		qtd++;
		for (int i = 1; i < n; i++) {
			if (s[i] == '<') qtd++;
			else break;
		}
	}
	
	if (s[n-1] == '>') {
		qtd++;
		for (int i = n-2; i >= 0; i--) {
			if (s[i] == '>') qtd++;
			else break;
		}
	}
	
	cout << qtd << endl;

	return 0;
}
