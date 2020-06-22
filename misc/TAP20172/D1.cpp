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

int count(int hour, int minute) {
	int c = 0;
	// consider 0 == 12
	for (int h = 0; h <= hour; h++) {
		int n1 = h / 10;
		int n2 = h % 10;
		if (h == 0) n1 = 1, n2 = 2;

		for (int m = 0; m < 60; m++) {
			if (h == hour && m > minute) break;
			
			int n3 = m / 10;
			int n4 = m % 10;
			
			if ((n1 == 0 || n2 - n1 == n3 - n2) && n3 - n2 == n4 - n3)
				c++;
		}
	}

	return c;
}

int main() {
	ios::sync_with_stdio(false);
	int d;	
	const int CYCLE = 720;
	cin >> d;

	int s = d % CYCLE;

	cout << count(s / 60, s % 60) + (s != d ? (d / CYCLE) * count(11, 59) : 0) << endl;

	return 0;
}
