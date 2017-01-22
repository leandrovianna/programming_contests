#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	const int N = 100;
	int n, m;
	vector<pair<int, int> > t;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			sum += a;
		}

		t.push_back(make_pair(sum, i+1));
	}

	sort(t.begin(), t.end());

	for (int i = 0; i < 3; i++)
		cout << t[i].second << endl;


	return 0;
}
