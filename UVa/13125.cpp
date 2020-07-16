// UVa - Water troubles - 13125
#include <bits/stdc++.h>
using namespace std;

const int M = 10;
int h[M], n;

void pass(int64_t flow, int i, vector<int64_t> &flows) {
  flows.push_back(flow);

  if (i == n) return;

  // add a tee
  pass(flow + h[i], i+1, flows);
  if (flow > h[i]) {
    pass(flow - h[i], i+1, flows);
  }

  // add a pump
  pass(flow * h[i], i+1, flows);

  // add a valve
  if (flow % h[i] == 0) {
    pass(flow / h[i], i+1, flows);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string line, token;
  int64_t t;

  while (getline(cin, line)) {
    istringstream iss(line);
    // get number T
    iss >> token;
    t = stoll(token);

    if (t == 0) break;

    for (n = 0; iss >> token; n++) {
      h[n] = stoi(token);
    }

    if (n == 1) {
      if (h[0] >= t)
        cout << h[0] << "\n";
      else
        cout << "0\n";
      continue;
    }

    vector<int64_t> flows;
    sort(h, h+n);
    do {
      pass(h[0], 1, flows);
    } while (next_permutation(h, h+n));

    int64_t max_flow = 0;

    for (const auto &flow : flows) {
      if (flow >= t && (max_flow == 0 || abs(max_flow - t) > abs(flow - t)))
          max_flow = flow;
    }

    cout << max_flow << "\n";
  }
  return 0;
}
