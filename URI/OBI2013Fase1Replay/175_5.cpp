#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
	const int N = 1e5;
	char* v[N];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		v[i] = (char*) malloc(2000 * sizeof(char));
		cin >> v[i];
	}

	int maior = 0;
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		size_t size = strlen(v[i]);
		unsigned int j = size-1;
		while (v[i][j] != '/')
			j--;

		if (size - j > maior)
			maior = size - j - 1;
	}

	sum -= maior;

	cout << sum << endl;
	return 0;
}
