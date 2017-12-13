//Codeforces - Exams - 479C
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, int> > exams(n);
	for (int i = 0; i < n; i++)
		cin >> exams[i].first >> exams[i].second;

	sort(exams.begin(), exams.end());
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (answer <= exams[i].second)
			answer = exams[i].second;
		else
			answer = exams[i].first;
	}

	cout << answer << endl;
	return 0;
}
