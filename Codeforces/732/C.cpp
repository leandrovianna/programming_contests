#include <iostream>
using namespace std;

typedef long long ll;

ll max(ll a, ll b) {
	return (a > b) ? a : b;
}

int main() {
	ll v[3];

	cin >> v[0] >> v[1] >> v[2];
	
	ll x = max(v[0], max(v[1],v[0]));
	ll lostMeals = 0;

	for (int i = 0; i < 3; i++)
		if (v[i] < x - 1)
			lostMeals += (x - 1) - v[i];

	cout << lostMeals << endl;

	return 0;
}
