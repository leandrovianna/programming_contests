//Codeforces - Nephren gives a riddle - 897C
#include <bits/stdc++.h>
using namespace std;

const int N = 100'010;
const string BASE = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string s1 = "What are you doing while sending \"";
const string s2 = "\"? Are you busy? Will you send \"";
const string s3 = "\"?";

uint64_t len[N];

char query(int n, uint64_t k) {
	if (n == 0) {
		if (k <= BASE.size())
			return BASE[k-1];
		else
			return '.';
	}

	if (k <= s1.size())
		return s1[k-1];

	else if (k <= s1.size() + len[n-1])
		return query(n-1, k - s1.size());

	else if (k <= s1.size() + len[n-1] + s2.size())
		return s2[k - s1.size() - len[n-1] - 1];

	else if (k <= s1.size() + len[n-1] + s2.size() + len[n-1])
		return query(n-1, k - s1.size() - len[n-1] - s2.size());

	else if (k <= s1.size() + len[n-1] + s2.size() + len[n-1] + s3.size())
		return s3[k - s1.size() - len[n-1] - s2.size() - len[n-1] - 1];

	else
		return '.';
}

int main() {
	ios::sync_with_stdio(false);
	int q, n;
	uint64_t k;

	len[0] = 75;
	for (int i = 1; i < N; i++)
		len[i] = 1'000'000'000'000'000'001;

	for (int i = 1; i < N; i++) {
		len[i] = 34 + len[i-1] + 32 + len[i-1] + 2;
		if (len[i] >= 1'000'000'000'000'000'001)
			break;
	}

	cin >> q;
	while (q--) {
		cin >> n >> k;
		cout << query(n, k);
	}
	cout << endl;
	
	return 0;
}
