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

const int P = 1e5;

bool isNotPrime[P];

void sieve() {
	
	// false == is prime
	memset(isNotPrime, 0, sizeof(isNotPrime));

	for (int i = 2; i*i < P; i++) {
		if (!isNotPrime[i]) {
			for (int j = 2; j*i < P; j++) {
				isNotPrime[j*i] = true;
			}
		}
	}
}

int main() {
	const long TO_MARS = 60 * 1e6;
	int peso, k;

	cin >> peso;

	sieve();

	k = 0;
	int kmh = 0;
	long hours = 0, days = 0;

	for (int i = peso; i < P && k < 10; i++) {
		if (!isNotPrime[i]) {
			k++;
			kmh += i;
		}
	}

	days = (TO_MARS / kmh) / 24;
	hours = (TO_MARS / kmh);

	cout << kmh << " km/h" << endl;
	cout << hours << " h / " << days << " d" << endl;

	return 0;
}
