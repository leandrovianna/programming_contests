//CodePit - Cairo's Market - F
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n;
struct vend {
	int id, x, y;
	vend() {}
	vend(int id, int x, int y) : id(id), x(x), y(y) {}
	bool operator<(vend v) {
		return this->x < v.x
			|| (this->x == v.x && this->y < v.y);
	}
};

vend v[N];

int solve(int id, int age) {

}

int main() {
	ios::sync_with_stdio(false);

	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v[i] = vend(i+1, x, y);
		}

		sort(v, v+n);

		cout << solve(0, 0) << endl;
	}

	return 0;
}
