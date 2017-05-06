#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define N 101000

int sieve[N];

void gen_sieve(int n) {
	memset(sieve, 0, sizeof(sieve));
	sieve[0] = sieve[1] = 1;
	for (int i = 2; i*i <= n; i++) {
		if (sieve[i] == 0) {
			for (int j = 2; j*i <= n; j++)
				sieve[i*j] = 1;
		}
	}
}

int main() {
	int t, n, qtd;
	long s;
	int primes[N], k = 0;
	bool pc[N];

	gen_sieve(N);

	for (int i = 0; i <= N; i++)
		if (sieve[i] == 0) primes[k++] = i;

	cin >> t;
	while (t-- > 0) {
		cin >> n;

		qtd = 0;
		memset(pc, 0, sizeof(pc));
		for (int i = 0; i < k; i++) {
			if (primes[i] > n) break;
			s = primes[i];
			for (int j = i+1; j < k; j++) {
				if (primes[j] > n) break;
				s += primes[j];
				if (s < N && sieve[s] == 0 && !pc[s]) 
					pc[s] = true, qtd++;
			}
		}

		cout << qtd << endl;
	}
	return 0;
}
