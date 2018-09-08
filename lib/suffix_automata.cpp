// Suffix Automaton
// LCS problem
#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
    vector<map<char, int>> edges; // edges[i] : edges of state i
    vector<int> link; // suffix link of state i
    vector<int> lenght; // lenght of longest string in class of state i
    int last, sz;
    vector<bool> term;

    SuffixAutomaton() {
        // add the initial node
        edges.push_back(map<char, int>());
        link.push_back(-1); // suffix link of first state is dummy
        lenght.push_back(0);
        term.push_back(false);
        last = 0; // initiate with index of first state
        sz = 0; // lenght of longest suffix added to automaton
    }

    SuffixAutomaton(string s) : SuffixAutomaton() {
        for (const auto &ch : s) {
            extend(ch);
        }
        find_terminals();
    }

    void extend(char ch) {
        // create new state for new equivalence (end-points) class
        edges.push_back(map<char, int>());
        sz++;
        lenght.push_back(sz);
        link.push_back(0);
        term.push_back(false);

        int r = edges.size() - 1;
        int p = last;

        while (p >= 0 && edges[p].find(ch) == edges[p].end()) {
            edges[p][ch] = r;
            p = link[p];
        }

        if (p != -1) {
            int q = edges[p][ch];
            if (lenght[p] + 1 == lenght[q]) {
                link[r] = q;
            } else {
                edges.push_back(edges[q]);
                lenght.push_back(lenght[p] + 1);
                link.push_back(link[q]);
                term.push_back(false);
                int qq = edges.size() - 1;
                link[q] = qq;
                link[r] = qq;

                while (p >= 0 && edges[p][ch] == q) {
                    edges[p][ch] = qq;
                    p = link[p];
                }
            }
        }

        last = r;
    }

    void find_terminals() {
        term = vector<bool>(edges.size(), false);
        int p = last;
        while (p >= 0) {
            term[p] = true;
            p = link[p];
        }
    }
};

int64_t lcs(SuffixAutomaton &sa, string t) {
    int st = 0, len = 0, best = 0, best_i = 0;

    for (int i = 0, sz = t.size(); i < sz; i++) {
        char ch = t[i];

        while (st != 0 && sa.edges[st].count(ch) == 0) {
            st = sa.link[st];
            len = sa.lenght[st];
        }

        if (sa.edges[st].count(ch) > 0) {
            st = sa.edges[st][ch];
            len++;
        }

        if (best < len) {
            best = len;
            best_i = i;
        }
    }

    //cout << t.substr(best_i-best+1, best) << endl;

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    string s, t;

    cin >> s >> t;

    SuffixAutomaton am(s);

    cout << lcs(am, t) << "\n";
    return 0;
}

