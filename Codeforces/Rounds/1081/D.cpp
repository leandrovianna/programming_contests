// Codeforces - Maximum Distance - 1081D
#include <bits/stdc++.h>
using namespace std;

namespace UF {
	const int N = 100 * 1000 + 10;
	int parent[N];
	int sz[N];
	void init(int size) {
	    assert(size < N);
		for (int i = 0; i < size; i++) {
			parent[i] = i;
			sz[i] = 1;
        }
	}

	int find(int x) {
		if (parent[x] == x) return x;
		else return parent[x] = find(parent[x]);
	}

	void join(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return;

        if (sz[x] < sz[y]) {
            parent[x] = y;
            sz[y] += sz[x];
        } else {
            parent[y] = x;
            sz[x] += sz[y];
        }
	}
}

struct edge {
    int x, y;
    int64_t w;
    bool operator< (const edge &other) {
        return this->w < other.w || (this->w == other.w && this->x < other.x);
    }
};

const int N = 100 * 1000 + 10;
const int64_t inf = 1e10;
edge edges[N];
vector<int> comp_queries[N];
int64_t comp_answer[N], answer[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k, x, y;
    int64_t w;

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> x;
        comp_queries[x].push_back(i);
        comp_answer[x] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> edges[i].x >> edges[i].y >> edges[i].w;
    }

    sort(edges, edges+m);

    UF::init(n+1);

    for (int i = 0; i < m; i++) {
        x = edges[i].x;
        y = edges[i].y;
        w = edges[i].w;

        if (UF::find(x) != UF::find(y)) {
            int small = UF::find(x), 
                large = UF::find(y);

            if (UF::sz[small] >= UF::sz[large]) {
                swap(small, large);
            }

            // note: should choose small and large in the same
            // manner that union-find do

            UF::join(x, y);

            if (comp_queries[small].size() > 0
                    && comp_queries[large].size() > 0) {
                comp_answer[large] = w;
            } else {
                comp_answer[large] = max(comp_answer[large],
                        comp_answer[small]);
            }

            for (const auto &id : comp_queries[small]) {
                comp_queries[large].push_back(id);
            }

            // store queries in large will maintain
            // access to queries, because UF::find return the large
            
            comp_queries[small].clear();
        }
    }

    for (int i = 0; i < N; i++) {
        for (const auto &id : comp_queries[i]) {
            answer[id] = comp_answer[i];
        }
    }

    for (int i = 0; i < k; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}
