// UVA - Bond - 11354
// similar to problem "Caminhoes"
// Kruskal and queries response inside kruskal
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

struct query {
    int x, y, ans = -1;
};

const int N = 100 * 1000 + 10;
edge edges[N];
query queries[N];
vector<int> comp_queries[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m, x, y, q;
    int64_t w;
    bool first = true;

    while (cin >> n >> m) {
        if (!first) {
            cout << "\n";
        }
        first = false;

        for (int i = 0; i < m; i++) {
            cin >> edges[i].x >> edges[i].y >> edges[i].w;
        }

        for (int i = 1; i <= n; i++) {
            comp_queries[i].clear();
        }

        cin >> q;

        for (int i = 0; i < q; i++) {
            cin >> x >> y;
            queries[i].x = x;
            queries[i].y = y;
            queries[i].ans = -1;

            comp_queries[x].push_back(i);
            comp_queries[y].push_back(i);
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

                for (const auto &id : comp_queries[small]) {
                    if (queries[id].ans == -1 && 
                            UF::find(queries[id].x) == UF::find(queries[id].y)) {
                        queries[id].ans = w;
                    } else {
                        comp_queries[large].push_back(id);
                    }
                }

                // store queries in large will maintain
                // access to queries, because UF::find return the large
                
                comp_queries[small].clear();
            }
        }

        for (int i = 0; i < q; i++) {
            cout << queries[i].ans << "\n";
        }
    }

	return 0;
}
