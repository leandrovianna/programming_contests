// Spoj - Lexicographical Substring Search - SUBLEX
#include <bits/stdc++.h>
using namespace std;

const int M = 100100; // length of string
const int N = 2*M, E = 270;

struct SuffixAutomaton {
  int edges[N][E];
  int link[N];
  int length[N];
  bool term[N];
  int last, sz;
  int states;

  void init() {
    memset(edges, -1, sizeof(edges));
    // add the initial node
    states = 1;
    link[0] = -1;
    length[0] = 0;
    term[0] = false;
    last = 0; // initiate with index of first state
    sz = 0; // length of longest suffix added to automaton
  }

  void from(string s) {
    init();
    for (const auto &ch : s) {
      extend(ch);
    }
    find_terminals();
  }

  void extend(char ch) {
    // create new state for new equivalence (end-points) class
    sz++;
    length[states] = sz;
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
      if (length[p] + 1 == length[q]) {
        link[r] = q;
      } else {
        for (int e = 0; e < E; e++) {
          edges[states][e] = edges[q][e];
        }
        length[states] = length[p] + 1;
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

int64_t dfs(SuffixAutomaton &sa, int st, int64_t d[]) {
  if (d[st] > 0) return d[st];

  d[st] = 1;

  for (int e = 0; e < E; e++) {
    if (sa.edges[st][e] != -1) {
      d[st] += dfs(sa, sa.edges[st][e], d);
    }
  }

  return d[st];
}

int64_t lcs(SuffixAutomaton &sa, string t) {
    int st = 0, len = 0, best = 0, best_i = 0;

    for (int i = 0, sz = t.size(); i < sz; i++) {
        char ch = t[i];

        while (st != 0 && sa.edges[st][(int)ch] == -1) {
            st = sa.link[st];
            len = sa.length[st];
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

string find_kth_substr(SuffixAutomaton &sa, int64_t d[], int k) {
  // should find the number of substring (array d) before
  // find kth substring

  int st = 0;
  string t = "";

  assert(k < d[0]);

  while (k > 0) {
    int acc = 1;
    for (int e = 0, nxt; e < E; e++) {
      nxt = sa.edges[st][e];
      if (nxt == -1) continue;

      if (k < acc + d[nxt]) {
        t += static_cast<char>(e);
        k -= acc;
        st = nxt;
        break;
      }

      acc += d[nxt];
    }
  }

  return t;
}

SuffixAutomaton sa;
int64_t d[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  sa.init();
  for (const auto &ch : s) {
    sa.extend(ch);
  }
  sa.find_terminals();

  memset(d, 0, sizeof(d));
  dfs(sa, 0, d);

  int q;
  cin >> q;
  for (int i = 0, k; i < q; i++) {
    cin >> k;
    cout << find_kth_substr(sa, d, k) << "\n";
  }
  return 0;
}
