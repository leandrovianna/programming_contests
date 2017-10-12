#include <bits/stdc++.h>
using namespace std;

int main() {
	int maior = 0;
	int64_t sum = 0;
	
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		
		sum += x;
		
		if (x > maior) {
			maior = x;
		}
	}
	
	int64_t r = sum - maior;
	
	cout << (maior <= r ? sum / 2 : r) << endl;
	return 0;
}
