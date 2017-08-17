#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

typedef unsigned long long u64;

map<string, i64> blood;
map<string, pair<string, string> > relation;

#define FOUNDER_NUMBER ((i64)1<<51)

i64 dfs(string c) {
	if (blood.find(c) != blood.end()) {
#ifdef DEBUG
		cout << "base case c:" << c << endl;
#endif
		return blood[c];
	} else if (relation.find(c) != relation.end()) {
		string p1 = relation[c].first,
			   p2 = relation[c].second;
#ifdef DEBUG
		cout << "c:" << c << " p1:" << p1 << " p2:" << p2 << endl;
#endif

		blood[c] += dfs(p1) / 2;

		blood[c] += dfs(p2) / 2;

		return blood[c];
	} else {
		return blood[c] = 0;
	}
}

int main() {
	string child, parent1, parent2;
	string founder;
	int n, m;

	cin >> n >> m;

	cin >> founder;

	for (int i = 0; i < n; i++) {
		cin >> child >> parent1 >> parent2;

		relation[child] = make_pair(parent1, parent2);
	}

	blood[founder] = FOUNDER_NUMBER;

	string ruler;
	i64 rulerScore = 0;
	for (int i = 0; i < m; i++) {
		cin >> child;

		dfs(child);

#ifdef DEBUG
		cout << child << ": " << blood[child] << endl;
#endif

		if (blood[child] > rulerScore) {
			ruler = child;
			rulerScore = blood[child];
		}
	}

	cout << ruler << endl;
	return 0;
}
