#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

const i64 MAX = 1e6 + 10;

i32 sp[MAX];
bool isprime[MAX];
map<i64, int> primes; //quantity of factors of a prime

void sieve() {
	for (i64 i = 0; i < MAX; i++) isprime[i] = true, sp[i] = 0;

	isprime[0] = false;
	isprime[1] = false;

	for (i64 i = 2; i < MAX; i+=2) sp[i] = 2;
	for (i64 i = 3; i < MAX; i+=2) {
		if (isprime[i]) {
			sp[i] = i;
			primes[i] = 0;
			for (i64 j = i; j*i < MAX; j+=2) {
				if (isprime[i*j]) {
					isprime[i*j] = false;
					if (sp[i*j] == 0) sp[i*j] = i;
				}
			}
		}
	}
}

int main() {
	int t;
	i64 n, x, r;
	sieve();

	ios::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;

		for (auto it = primes.begin(); it != primes.end(); it++) {
			it->second = 0;
		}

		x = n;
		while (sp[x] != x) {
			primes[sp[x]]++;
			x /= sp[x];
		}
		primes[x]++;

		r = 1;
		for (auto it = primes.begin(); it != primes.end(); it++) {
			r *= it->second+1;
		}

		cout << r << endl;
	}

	return 0;
}
