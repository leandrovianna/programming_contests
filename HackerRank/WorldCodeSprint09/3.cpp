#include <iostream>
using namespace std;

#define K 100000

int main() {
	int n, k;
	pair queen;
	pair ob[K];

	cin >> n >> k;
	cin >> queen.first >> queen.second;
	for (int i = 0; i < k; i++)
		cin >> ob[i].first >> ob[i].second;

	return 0;
}
