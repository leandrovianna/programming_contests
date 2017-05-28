#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long n, k, res;
	int t;

	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> n >> k;	
		k--;

		res = n / k;
		if (n % k > 0) res++;

		cout << "Caso " << ti << ": " << res << endl;
	}	
	return 0;
}
