// Codeforces Gym - 100803 - Asian Tokyo ICPC 2014 - F - There is no alternative
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

const int M = 50100, N = 550;
edge edges[M];
int mst_idx[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> edges[i].x >> edges[i].y
            >> edges[i].w;
    }

    sort(edges, edges+m);

    UF::init(n+1);

    int x, y;
    int64_t w, mst_cost = 0;
    int sz = 0;

    for (int i = 0; i < m; i++) {
        x = edges[i].x;
        y = edges[i].y;
        w = edges[i].w;

        if (UF::find(x) != UF::find(y)) {
            mst_cost += w;
            mst_idx[sz++] = i;
            UF::join(x, y);
        }
    }

    int64_t answer_cost = 0;
    int answer_count = 0;

    for (int j = 0; j < sz; j++) {
        int64_t new_mst_cost = 0;

        UF::init(n+1);
        for (int i = 0; i < m; i++) {
            if (i == mst_idx[j]) // do not include edge mst_idx[j]
                continue;

            x = edges[i].x;
            y = edges[i].y;
            w = edges[i].w;

            if (UF::find(x) != UF::find(y)) {
                new_mst_cost += w;
                UF::join(x, y);
            }
        }

        if (new_mst_cost != mst_cost) {
            answer_cost += edges[mst_idx[j]].w;
            answer_count++;
        }
    }

    cout << answer_count << " " << answer_cost << "\n";
    return 0;
}
