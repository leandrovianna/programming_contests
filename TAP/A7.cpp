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

int main() {
	int v, e;

	while (cin >> v >> e) {
		cout << (2 - v + e) << endl;
	}
	return 0;
}
