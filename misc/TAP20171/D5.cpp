#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

int main() {
	int x, y, n, p;
	string s;

	cin >> n;
	while (n-- > 0) {
		cin >> s;
		
		if (s == "P=NP") {
			cout << "skipped" << endl;
		} else {
			p = s.find("+");
			x = atoi(s.substr(0, p).c_str());
			y = atoi(s.substr(p+1).c_str());
			cout << x + y << endl;
		}
	}
	return 0;
}
