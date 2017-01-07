#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int t, n, input, s, greater, journey, x;
	vector<int> v;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> input;
			v.push_back(input);
		}

		sort(v.begin(), v.end());
		journey = 0;

		while (v.size() > 0) {
			greater = v.back();
			x = ceil(50.0 / greater);

			if (v.size() < x)
				break;

			v.erase(v.begin(), v.begin() + x - 1);
			v.pop_back();
			journey++;
		}

		v.clear();

		cout << "Case #" << i+1 << ": " << journey << endl;
	}
	return 0;
}
