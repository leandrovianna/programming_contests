#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

class RelativeHeights
{
    public:
	int countWays(vector<int> h) {
		set<vector<int> > s;
		for (int i = 0; i < h.size(); i++) {
			auto p = genprofile(h, i);

			s.insert(p);
		}

		return s.size();
	}

	vector<int> genprofile(vector<int> h, int i) {
		vector<int> p(h.size()-1);
		map<int, int> mp; // value -> pos

		int pos = 0;
		for (int j = 0; j < h.size(); j++) {
			if (j != i) mp[h[j]] = pos++;
		}

		sort(h.begin(), h.end(), greater<int>());

		pos = 0;
		for (int j = 0; j < h.size(); j++) {
			if (mp.find(h[j]) != mp.end())
				p[mp[h[j]]] = pos++;
		}

		return p;
	}
};

int main() {
	ios::sync_with_stdio(false);
		
	RelativeHeights* rh = new RelativeHeights();
	cout << rh->countWays({10, 30, 40, 50}) << endl;
	cout << rh->countWays({40, 20, 10, 30}) << endl;
	cout << rh->countWays({10, 20, 40, 100, 120}) << endl;
	return 0;
}
