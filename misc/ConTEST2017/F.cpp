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

typedef struct {
	int x, y;
} Point;

int main() {
	Point P, Q, R;
	int D;
	int t;
	string res;

	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> P.x >> P.y;
		cin >> Q.x >> Q.y;
		cin >> R.x >> R.y;
		D = (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);	

		if (D > 0)
			res = "anti-horario";
		else if (D < 0)
			res = "horario";
		else
			res = "indeterminado";

		cout << "Caso " << ti << ": " << res << endl;
	}

	return 0;
}
