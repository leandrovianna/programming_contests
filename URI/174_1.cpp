#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	const int N = 5;
	double v[N];	
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v, v+N);
	double sum = 0;
	for (int i = 1; i < N-1; ++i) {
		sum += v[i];	
	}

	cout << fixed << setprecision(1) << sum << endl;
	return 0;
}
