#include <bits/stdc++.h>
using namespace std;

// versao com namespace
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

// versao usando um struct
const int N = 100 * 1000 + 10;
struct union_find {
    int parent[N];
    int sz[N];

    union_find() {
    }

    void init(int size) {
        assert(size < N);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = find(parent[x]);
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
};

int main() {
	ios::sync_with_stdio(false);

	return 0;
}
