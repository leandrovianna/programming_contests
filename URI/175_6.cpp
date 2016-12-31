#include <iostream>
using namespace std;

int main() {
	long long a1, b1, a2, b2, a, b;
	string res;

	cin >> a1 >> b1;
	cin >> a2 >> b2;
	cin >> a >> b;

	res = "N";

	if ( (a1 >= a || a2 >= a)
		&& (b1 >= b || b2 >= b) )
			res = "S";
	else if ( (b1 >= a || b2 >= a)
		&& (a1 >= b || a2 >= b) )
			res = "S";

	cout << res << endl;
	
	return 0;
}
