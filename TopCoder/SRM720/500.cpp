#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

const long long tens[] = {1, 10, 100, 1000, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};

class MinProduct {
	public:
	long long findMin(vector <int> amount, int blank1, int blank2) {
		vector<int> aux = amount;
		long long ans = LLONG_MAX;
		
		for (int mask = 0; mask < (1 << (blank1+blank2)); mask++) {
			amount = aux;
			long long a = 0, b = 0;
			int k = blank1-1, l = blank2-1;
			if (__builtin_popcount(mask) == blank1) {
				for (int i = 0; i < blank1+blank2; i++) {
					for (int j = 0; j < 10; j++) {
						if (amount[j] > 0) {
							amount[j]--;
							if (mask & (1 << i)) 
								a += j * tens[k--]; 
							else 
								b += j * tens[l--];
							
							break;
						}
					}
				}
			//	cout << a << " " << b << endl;
				ans = min(ans, a*b);
			}
		}
		
		return ans;
	}
};
