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
	set<string> pomekons;
	int n;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		pomekons.insert(s);
	}

	cout << "Falta(m) " << 151 - pomekons.size() << " pomekon(s)." << endl;
	return 0;
}
