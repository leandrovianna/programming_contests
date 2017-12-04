#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int t, n, c, e, qtd, p, x, y;
	set<pair<int, int> > cameras;

	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		cin >> n >> c;
		for (int i = 0; i < c; i++) {
			cin >> x >> y;
			cameras.insert({x,y});
		}
		
		cin >> e;
		qtd = 0;
		for (int i = 0; i < e; i++) {
			cin >> p;
			auto it = lower_bound(cameras.begin(), cameras.end(),
					pair<int,int>{p,p});
			if (it != cameras.end()) {
				cout << "*" << p << endl;
				qtd++;
			}
		}

		cout << "Caso #" << ti+1 << ": " << qtd << '\n';
		cameras.clear();
	}	
	return 0;
}
