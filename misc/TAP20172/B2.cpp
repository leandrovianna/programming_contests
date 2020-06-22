#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

int main() {
	ios::sync_with_stdio(false);
	int n, op, x;
	string s;
	vector<pair<int, string> > vs;

	cin >> n;
	while (n--) {
		cin >> s >> op;
		vs.push_back(make_pair(op, s));
	}

	int cont = 0;
	for (int i = 1; i <= 100; i++) {
		x = i;
		for (auto& p : vs) {
			if (p.second == "SUBTRACT") {
				x -= p.first;
				if (x < 0) {
					cont++; break;
				}
			}
			if (p.second == "DIVIDE") {
				if (x % p.first == 0)
					x /= p.first;
				else {
					cont++; break;
				}
			}
			if (p.second == "ADD") x += p.first;
			if (p.second == "MULTIPLY") x *= p.first;
		}
	}

	cout << cont << endl;
	return 0;
}
