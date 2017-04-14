#include <iostream>
#include <map>
#include <cstring>
using namespace std;

#define J 1000000
#define A 1000002

typedef struct {
	char size;
	int num;
} Jersey;

int main() {
	long j, a, n;
	map<char, long> jerseys;
	bool numbers[A];
	Jersey requests[J];
	char c;

	cin >> j >> a;

	jerseys['S'] = 0;
	jerseys['M'] = 0;
	jerseys['L'] = 0;
	memset(numbers, 0, sizeof(numbers));

	for (long i = 0; i < j; i++) {
		cin >> c;
		jerseys[c]++;
	}
	
	long qtd = 0;

	for (long i = 0; i < a; i++) {
		cin >> c >> n;
		requests[i].size = c;
		requests[i].num = n;
	}

	cout << qtd << endl;
	return 0;
}
