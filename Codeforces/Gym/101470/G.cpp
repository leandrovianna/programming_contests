// Codeforces Gym - Grammar - 101470G
#include <bits/stdc++.h>
using namespace std;

uint8_t id(char c) {
  assert(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));

  if ('A' <= c && c <= 'Z')
    return c - 'A';
  else
    return c - 'a';
}

struct Rule {
  char c1, c2;
  bool terminal;
  Rule(char c) : c1(c), c2(c), terminal(true) {}
  Rule(char c1, char c2) : c1(c1), c2(c2), terminal(false) {}
};

const int E = 30;
vector<Rule> rules[E];
// nxt[r][x] -> rules that produces the char x from rule r
vector<int> nxt[E][E];

bool processed[E];
void build(char P) {
  if (processed[id(P)])
    return;
  processed[id(P)] = true;

  int idx = 0;
  for (const auto &rule : rules[id(P)]) {
    if (rule.terminal) {
      nxt[id(P)][id(rule.c1)].push_back(idx);
    } else {
      build(rule.c1);
      for (int e = 0; e < E; e++) {
        if (nxt[id(rule.c1)][e].size() > 0)
          nxt[id(P)][e].push_back(idx);
      }

      build(rule.c2);
    }

    idx++;
  }
}

bool test(const string &s, char P, int i, int l) {
  for (const auto &rule_index : nxt[id(P)][id(s[i])]) {
    const auto &rule = rules[id(P)][rule_index];
    if (rule.terminal) {
      if (rule.c1 == s[i] && l == 1)
        return true;
    } else {
      for (int s1 = 1, s2; s1 < l; s1++) {
        s2 = l - s1;
        bool found = test(s, rule.c1, i, s1);
        if (found) {
          found = test(s, rule.c2, i+s1, s2);
          if (found)
            return true;
        }
      }
    }
  }
 
  return false;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  //ifstream fin("g.in");
  ifstream fin(argv[argc-1]);

  string x;
  getline(fin, x);

  string rule;
  char A, B, C, a;
  while (getline(fin, rule)) {
    istringstream iss(rule);

    // terminal prod. rule
    if (rule.size() == 2) {
      iss >> A >> a;
      rules[id(A)].emplace_back(a);
    } else {
      // non-terminal prod. rule
      iss >> A >> B >> C;
      rules[id(A)].emplace_back(B, C);
    }
  }

  build('S');
  int n = x.size();
  if (test(x, 'S', 0, n))
    cout << "1\n";
  else
    cout << "0\n";
  return 0;
}
