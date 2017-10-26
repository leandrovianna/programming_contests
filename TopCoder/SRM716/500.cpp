#include <bits/stdc++.h>
using namespace std;

class ConstructLCSEasy {
	public:
		string construct(int ab, int bc, int ca) {
			string a, b, c;

			a.append("0", ab);
			b.append("0", ab);
			b.append("1", bc);
			c = b;

			return a + " " + b + " " + c;
		}
};
