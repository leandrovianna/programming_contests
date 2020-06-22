#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

#define INF 100000
#define M 1000

int main() {
	char grid[M][M];		
	int m, n;
	vector<pair<int, int> > ps;
	int safe_pos = 0;
	pair<int, int> s;
	double dist_safe = INF, dist;
	
	cin >> n;
	cout << fixed << setprecision(2);
	for (int ni = 0; ni < n; ni++) {
		ps.clear();
		dist_safe = INF;
		safe_pos = 0;

		cin >> m;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 's')
					s = make_pair(i, j);
				else if (grid[i][j] == 'p')
					ps.push_back(make_pair(i, j));
			}
		}

		for (size_t i = 0; i < ps.size(); i++) {
			dist = hypot(ps[i].first - s.first, ps[i].second - s.second);
			if (dist_safe > dist) {
				dist_safe = dist;
				safe_pos = i;
			}
		}

		cout << "(" << s.first << "," << s.second << "):("
			<< ps[safe_pos].first << "," << ps[safe_pos].second
			<< "):" << dist_safe << endl;
	}
	return 0;
}
