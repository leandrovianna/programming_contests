// Spoj - New Distinct Substrings - SUBST1
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

  void init() {
    memset(edges, -1, sizeof(edges));
    // add the initial node
    states = 1;
    link[0] = -1;
    lenght[0] = 0;
    term[0] = false;
    last = 0; // initiate with index of first state
    sz = 0; // lenght of longest suffix added to automaton
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
} sa;

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

int64_t d[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sa.init();
    for (const auto &ch : s) {
      sa.extend(ch);
    }
    sa.find_terminals();

    memset(d, 0, sizeof(d));
    cout << dfs(sa, 0, d) - 1 << "\n";
  }
  return 0;
}
