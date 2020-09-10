// Codeforces Gym - Variable Shadowing - 100513M
#include <bits/stdc++.h>
using namespace std;

const int N = 52 * 52;
const int C = 30;

int parent[N];

struct Var {
  int r = 0, c = 0;
};
Var vars[N][C];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  cin.ignore();

  stack<int> backtrace;
  backtrace.push(0);
  parent[0] = -1;
  int scopes = 1;

  string line;
  for (int r = 1; r <= n; r++) {
    getline(cin, line);
    for (int c = 1, m = line.size(); c <= m; c++) {
      char &ch = line[c-1];
      if (ch == '{') {
        parent[scopes] = backtrace.top();
        backtrace.push(scopes);
        scopes++;
      } else if (ch == '}') {
        backtrace.pop();
      } else if (!isspace(ch)) {
        vars[backtrace.top()][ch - 'a'] = Var{r, c};
      }
    }
  }

  vector<tuple<int, int, int, int, char>> answers;

  for (int i = 0, j; i < scopes; i++) {
    for (int e = 0; e < 26; e++) {
      Var v1 = vars[i][e];
      if (v1.r == 0) continue; // no declaration

      j = parent[i];
      while (j != -1) {
        Var v2 = vars[j][e];
        if (v2.r != 0 && (v2.r < v1.r || (v2.r == v1.r && v2.c < v1.c))) {
          answers.push_back({vars[i][e].r, vars[i][e].c,
              vars[j][e].r, vars[j][e].c, (char) ('a' + e)});
          break;
        }
        j = parent[j];
      }
    }
  }

  sort(answers.begin(), answers.end(),
      [](const auto &a, const auto &b) {
    return get<0>(a) < get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b));
  });

  int r1, c1, r2, c2;
  char name;
  for (const auto &ans : answers) {
    tie(r1, c1, r2, c2, name) = ans;
    cout << r1 << ":" << c1 << ": warning: shadowed declaration of " << name
      << ", the shadowed position is " << r2 << ":" << c2 << "\n";
  }

  return 0;
}
