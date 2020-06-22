#include <iostream>
#include <stack>
using namespace std;

#define N 100000

int main() {
	stack<int> s;
	int d, k, sum;

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> d;
		
		if (d == 0)
			s.pop();
		else
			s.push(d);
	}

	sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << endl;

	return 0;
}
