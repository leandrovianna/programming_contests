// Codeforces Gym - Fygon - 100801F - 2015 NEERC Nothern Subregional
#include <bits/stdc++.h>
using namespace std;

struct Statement {
  bool isLag;
  int indent;
  char var;
  char limit;

  Statement(int indent = 0) : isLag(true), indent(indent) {
  }

  Statement(int indent, char var, char limit)
    : isLag(false), indent(indent), var(var), limit(limit) {
  }
};

const int M = 25;
Statement program[M];
int programsize = 0;
const int A = 260;
int memory[A];
int endblock[M];

int exec(int n) {
  fill(memory, memory+A, 0);
  memory['n'] = n;

  stack<int> loop;
  int pc = 0, op = 0;

  fill(endblock, endblock+M, -1);
  while (pc < programsize) {
    const auto &stat = program[pc];
    if (!stat.isLag) {
      loop.push(pc);
    }

    pc++;
    while (!loop.empty() && program[pc].indent <= program[loop.top()].indent) {
      endblock[loop.top()] = pc-1;
      loop.pop();
    }

    if (!loop.empty()) {
      endblock[loop.top()] = pc;
    }
  }

  while (pc < programsize) {
    const auto &stat = program[pc];

    if (stat.isLag) {
      op++;
    } else {
      if (loop.empty() || loop.top() != pc) {
        // new loop
        loop.push(pc);
        memory[(int)stat.var] = 0;
      } else {
        memory[(int)stat.var]++;
      }

      int limit = isalpha(stat.limit)
        ? memory[(int)stat.limit] : stat.limit - '0';

      if (memory[(int)stat.var] == limit) {
        pc = endblock[pc];
        endblock[pc] = -1;
        loop.pop();
      }
    }

    if (!loop.empty() && endblock[loop.top()] == pc)
      pc = loop.top();
    else
      pc++;
  }

  return op;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string line, token;
  while (getline(cin, line)) {
    int indent = 0;
    while (line[indent] == ' ') {
      indent++;
    }

    istringstream iss(line);
    iss >> token;
    if (token == "lag") {
      program[programsize++] = Statement(indent);
    } else if (token == "for") {
      char var;
      iss >> var;
      iss.ignore(10); // ignore [blank]in[blank]range(
      char limit;
      iss >> limit;
      program[programsize++] = Statement(indent, var, limit);
    }
  }

  vector<pair<int, int>> values;
  for (int n = 0; n <= 6; n++) {
    int lagOps = exec(n);
    cout << n << " => " << lagOps << endl;
    values.emplace_back(n, lagOps);
  }

  return 0;
}
