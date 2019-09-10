// Codeforces - Prefixes and Suffixes - 432D
#include <bits/stdc++.h>
using namespace std;

const int N = 200100, E = 270;

struct SuffixAutomaton {
    int edges[N][E];
    int link[N];
    int lenght[N];
    bool term[N];
    int last, sz;
    int states;

    SuffixAutomaton() {
        memset(edges, -1, sizeof(edges));
        // add the initial node
        states = 1;
        link[0] = -1;
        lenght[0] = 0;
        term[0] = false;
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
        sz++;
        lenght[states] = sz;
        link[states] = 0;
        term[states] = false;
        states++;

        int r = states - 1;
        int p = last;

        while (p >= 0 && edges[p][(int)ch] == -1) {
            edges[p][(int)ch] = r;
            p = link[p];
        }

        if (p != -1) {
            int q = edges[p][(int)ch];
            if (lenght[p] + 1 == lenght[q]) {
                link[r] = q;
            } else {
                for (int e = 0; e < E; e++) {
                    edges[states][e] = edges[q][e];
                }
                lenght[states] = lenght[p] + 1;
                link[states] = link[q];
                term[states] = false;
                states++;

                int qq = states - 1;
                link[q] = qq;
                link[r] = qq;

                while (p >= 0 && edges[p][(int)ch] == q) {
                    edges[p][(int)ch] = qq;
                    p = link[p];
                }
            }
        }

        last = r;
    }

    void find_terminals() {
        memset(term, 0, sizeof(term));
        int p = last;
        while (p >= 0) {
            term[p] = true;
            p = link[p];
        }
    }
};

void dfs(SuffixAutomaton &sa, int occur[], int words[], int st) {
    if (occur[st] > 0)
        return;

    int64_t occ = 0, wrd = 0;

    if (sa.term[st]) {
        occ++;
        wrd++;
    }

    for (int e = 0; e < E; e++) {
        if (sa.edges[st][e] != -1) {
            int newst = sa.edges[st][e];
            dfs(sa, occur, words, newst);
            occ += occur[newst];
            wrd += words[newst] + occur[newst];
        }
    }

    occur[st] = occ;
    words[st] = wrd;
}

int64_t lcs(SuffixAutomaton &sa, string t) {
    int st = 0, len = 0, best = 0, best_i = 0;

    for (int i = 0, sz = t.size(); i < sz; i++) {
        char ch = t[i];

        while (st != 0 && sa.edges[st][(int)ch] == -1) {
            st = sa.link[st];
            len = sa.lenght[st];
        }

        if (sa.edges[st][(int)ch] != -1) {
            st = sa.edges[st][(int)ch];
            len++;
        }

        if (best < len) {
            best = len;
            best_i = i;
        }
    }

    cout << t.substr(best_i-best+1, best) << endl;

    return best;
}

string find_kth_substr(SuffixAutomaton &sa, int k) {
    int occur[N], words[N];
    dfs(sa, occur, words, 0);

    // find kth substring

    int st = 0;
    string t = "";

    int64_t prev_k = k;
    while (k > 0) {
        int64_t acc = 0, tmp;

        for (int e = 0; e < E; e++) {
            if (sa.edges[st][e] != -1) {
                int newst = sa.edges[st][e];
                tmp = acc;
                acc += words[newst];
                if (acc >= k) {
                    st = newst;
                    k -= tmp + occur[newst];
                    t += static_cast<char>(e);
                    break;
                }
            }
        }

        if (k == prev_k) {
            t = "No such line.";
            break;
        }

        prev_k = k;
    }

    return t;
}

SuffixAutomaton sa;
int occurs[N], words[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;

    cin >> s;

    for (const auto &ch : s) {
        sa.extend(ch);
    }
    sa.find_terminals();

    dfs(sa, occurs, words, 0);

    int l = 1, st = 0;
    vector<pair<int, int>> answers;
    for (const auto &ch : s) {
        if (sa.edges[st][(int)ch] != -1) {
            st = sa.edges[st][(int)ch];

            if (sa.term[st]) {
                answers.push_back({l, occurs[st]});
            }
        }

        l++;
    }

    cout << answers.size() << "\n";
    for (const auto &p : answers) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
