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
	string s;
	bool r;
	int n, ans;
	ios::sync_with_stdio(true);

	while (cin >> s && s != ".") {
		n = s.size();

		ans = 1;
		for (int i = n; i >= 2; i--) {
			if (n % i == 0) {
				r = true;
				for (int j = n/i; j < n; j++) {
					// cout << s << endl;
					// cout << j << ": " << s[j] 
					// 	<< " != " 
					// 	<< j-(n/i) << ": " << s[j-(n/i)] << endl;

					if (s[j] != s[j-(n/i)]) {
						r = false;
						break;
					}
				}

				if (r) {
					ans = i;
					break;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
