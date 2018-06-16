#include <iostream>
using namespace std;

int main() {
	const int N = 1e5;
	int n, v[N];	

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	long sum1 = v[0];
	long sum2 = v[n-1];
	int i1 = 0, i2 = n-1;
	while (sum1 != sum2 || i1+1 != i2) {
		if (sum1 < sum2) {
			sum1 += v[++i1];	
		}
		else { 
			sum2 += v[--i2];	
		}
	}

	cout << i1 + 1 << endl;
	return 0;
}
