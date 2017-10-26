//SRM716 - 250 - Accepted
//Wrong Answer
#include <bits/stdc++.h>
using namespace std;

class Permutiple {
	public:
		std::string isPossible(int x) {
			std::string num;
			for (int e = 1; x/e > 0; e *= 10) {
				num = to_string( (x / e) % 10) + num;
			}

			bool ans = false;

			while (next_permutation(num.begin(), num.end())) {
				int a = stoi(num);
				if (a % x == 0) {
					ans = true;
					break;
				}
			}

			return (ans ? "Possible" : "Impossible");
		}
};

int main() {
	Permutiple p;
	cout << p.isPossible(142857) << endl;
	cout << p.isPossible(14) << endl;
	cout << p.isPossible(1035) << endl;
	cout << p.isPossible(1000000) << endl;


	return 0;
}
