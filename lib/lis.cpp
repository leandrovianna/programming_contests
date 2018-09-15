#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	const int N = 1000;
    int n;
    int64_t a[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

	set<int64_t> st;
	auto it = st.begin();
    for (int i = 0; i < n; i++) {
		if (st.find(a[i]) != st.end()) continue;

		st.insert(a[i]);
		it = st.find(a[i]);
		if (next(it) != st.end())
			st.erase(next(it));
	}

	cout << st.size() << endl;

	return 0;
}
