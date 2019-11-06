// Spoj - Fast Maximum Matching - MATCHING
// Augmenting Path for MCBM
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int match[N], lmatch[N];
bool visited[N];
 
int augment(int v) {
    assert(0 <= v && v < N);

	if (visited[v]) return 0;
	visited[v] = true;
 
    for (const auto &u : g[v]) {
		if (match[u] == -1) {
			match[u] = v;
			lmatch[v] = u;
			return 1;
		}
	}

    for (const auto &u : g[v]) {
		if (augment(match[u])) {
			match[u] = v;
			lmatch[v] = u;
			return 1;
		}
	}
 
	return 0;
}
 
int matching(int left_sz) {
	memset(match, -1, sizeof(match));
	memset(lmatch, -1, sizeof(lmatch));
 
	int mcmb = 0, m;
	bool keep = true;
 
    while (keep) {
        keep = false;

        for (int i = 0; i < left_sz; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < left_sz; i++) {
            if (lmatch[i] == -1) {
                m = augment(i);
                mcmb += m;
                if (m > 0)
                    keep = true;
            }
        }
    }
 
	return mcmb;
}

int getCow(int i) {
    return i;
}

const int C = 50010;
int getBull(int i) {
    return C + i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;

    cin >> n >> m >> p;

    for (int i = 0, a, b; i < p; i++) {
        cin >> a >> b;
        a--;
        b--;

        g[getCow(a)].push_back(getBull(b));
        g[getBull(b)].push_back(getCow(a));
    }

    cout << matching(n) << "\n";

    return 0;
}
