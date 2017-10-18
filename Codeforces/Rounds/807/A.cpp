#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long i32;
typedef long long i64;

#define N 10000

int main() {
	int n;
	pair<int, int> rat[N];

	cin >> n;
	for (int ti = 0; ti < n; ti++) {
		cin >> rat[ti].first >> rat[ti].second;		
	}

	for (int i = 0; i < n; i++) {
		if (rat[i].first != rat[i].second) {
			cout << "rated" << endl;
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (rat[i].second < rat[j].second) {
				cout << "unrated" << endl;
				return 0;
			}
		}
	}

	cout << "maybe" << endl;
	return 0;
}
