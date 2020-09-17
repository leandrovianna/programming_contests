// Codeforces Gym - Baby Name - 102700B
#include <bits/stdc++.h>
using namespace std;

const int M = 200100;
const int N = 2*M, E = 30;

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
    last = 0; // initiate first state
    sz = 0; // length of longest suffix
  }

  void from(string s) {
    init();
    for (const auto &ch : s) {
      extend(ch);
    }
  }

  int id(char ch) {
    return ch - 'a';
  }

  void extend(char ch) {
    // create new state for new equivalence (end-point) class
    sz++;
    length[states] = sz;
    link[states] = 0;
    term[states] = false;
    states++;

    int r = states - 1;
    int p = last;

    while (p >= 0 && edges[p][id(ch)] == -1) {
      edges[p][id(ch)] = r;
      p = link[p];
    }

    if (p != -1) {
      int q = edges[p][id(ch)];
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

        while (p >= 0 && edges[p][id(ch)] == q) {
          edges[p][id(ch)] = qq;
          p = link[p];
        }
      }
    }

    last = r;
  }
};

SuffixAutomaton sa[2];

string answer = "";

void dfs(int st, int aut) {
  if (st == 0 && aut == 0) {
    // primeiro automato, garantindo nao vazio

    for (int e = E-1; e >= 0; e--) {
      if (sa[aut].edges[st][e] != -1) {
        answer += ((char)'a' + e);
        dfs(sa[aut].edges[st][e], aut);
        break;
      }
    }
  } else {
    // descendo no maior caracter
    for (int e = E-1; e >= 0; e--) {
      if (aut == 0 && sa[aut].edges[st][e] == -1) {
        // primeiro automato, nao tem caracter maior
        if (sa[1].edges[0][e] != -1) {
          // segundo automato, tem caracter maior no 1o estado
          answer += ((char)'a' + e);
          dfs(sa[1].edges[0][e], 1);
          break;
        }
      }

      if (sa[aut].edges[st][e] != -1) {
        answer += ((char)'a' + e);
        dfs(sa[aut].edges[st][e], aut);
        break;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  sa[0].from(s1);
  sa[1].from(s2);

  dfs(0, 0);

  cout << answer << "\n";

  return 0;
}
