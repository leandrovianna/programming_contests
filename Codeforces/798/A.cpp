#include <iostream>
using namespace std;

int main() {
	string s;	

	cin >> s;

	int qtd = 0;
	for (int i = 0; i < s.size()/2; i++) {
		if (s[i] != s[s.size()-i-1])
			qtd++;
	}

	if ((s.size() % 2 == 0 && qtd == 1)
			|| s.size() % 2 != 0 && qtd < 2) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}
