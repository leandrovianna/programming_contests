#include <iostream>
using namespace std;

int solve(int b, int c) {
	if (b < c) return 0;
	return (b / c) + solve(b / c + b % c, c);
}

int main() {
	int e, f, c;

	cin >> e >> f >> c;

	int qtd = solve(e + f, c);
	
	cout << qtd << endl;
	return 0;
}
