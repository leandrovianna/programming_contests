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

const int MAX = 100100;
const int T = 100;
const int MOD = 1000000007;

int sp[MAX];
bool isprime[MAX];
map<i32, int> primes; //quantity of factors of a prime

void sieve() {
	for (size_t i = 0; i < MAX; i++) isprime[i] = true, sp[i] = 0;

	isprime[0] = false;
	isprime[1] = false;

	for (size_t i = 2; i < MAX; i+=2) sp[i] = 2;
	for (size_t i = 3; i < MAX; i+=2) {
		if (isprime[i]) {
			sp[i] = i;
			primes[i] = 0;
			for (size_t j = i; j*i < MAX; j+=2) {
				if (isprime[i*j]) {
					isprime[i*j] = false;
					if (sp[i*j] == 0) sp[i*j] = i;
				}
			}
		}
	}
}

typedef struct {
	int ti;
	i32 n;
	i32 r;
} entry;

bool comp1(entry a, entry b) {
	return (a.ti < b.ti);
}
bool comp2(entry a, entry b) {
	return (a.n < b.n);
}

int main() {
	int t;
	entry entries[T];
	i32 z, x , qtd;
	int facts[MAX];

	sieve();

	cin >> t;
	for (int i = 0; i < t; i++) {
		entries[i].ti = i+1;
		cin >> entries[i].n;
	}

	sort(entries, entries+t, comp2);

	z = 2;
	for (int i = 0; i < t; i++) {

		for (i32 j = entries[i].n; j >= z; j--) {
			x = j;
			while (sp[x] != x) {
				primes[sp[x]]++;
				x /= sp[x];
			}
			primes[x]++;
		}

		z = entries[i].n + 1;

		qtd = 0;

		for (auto it = primes.begin(); it != primes.end(); it++) {
			if (it->second >= 2) {
				facts[qtd] = it->second / 2;
				qtd++;
			}
		}

		// d = 2^x^2 * 3^y^2 ...
		// r = (x+1) * (y+1);
		// r = (facts[0]+1) * (facts[1]+1) * ... * (facts[qtd-1]+1)

		entries[i].r = 1;
		for (int j = 0; j < qtd; j++) {
			entries[i].r = (entries[i].r % MOD * (facts[j]+1) % MOD) % MOD;
		}

	}

	sort(entries, entries+t, comp1);

	for (int i = 0; i < t; i++) {
		cout << "Caso " << entries[i].ti << ": " << entries[i].r << endl;
	}
	
	return 0;
}
