// Codeforces - Playoff Tournament - 1535D
#include <bits/stdc++.h>
using namespace std;

const int K = 18;
string results;
int tree[(1<<K)+100];

void calc(int x, int n) {
  int lf = 1, rg = 1;
  if (2*x+1 < n) {
    lf = tree[2*x+1];
  }

  if (2*x+2 < n) {
    rg = tree[2*x+2];
  }

  switch (results[x]) {
    case '?':
      tree[x] = lf + rg;
      break;
    case '1':
      tree[x] = lf;
      break;
    case '0':
      tree[x] = rg;
      break;
  }
}

void build(int i, int n) {
  if (2*i+1 < n) {
    build(2*i+1, n);
  }

  if (2*i+2 < n) {
    build(2*i+2, n);
  }

  calc(i, n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k;
  cin >> k;

  cin >> results;
  reverse(results.begin(), results.end());

  const int n = results.size();

  build(0, n);

  char ch;
  int q, p;
  cin >> q;
  while (q--) {
    cin >> p >> ch;

    p--;
    int x = n-1-p;
    results[x] = ch;

    while (x > 0) {
      calc(x, n);
      // cout << x << " " << tree[x] << endl;
      x = ((x+1) / 2) - 1;
    }

    calc(0, n);

    cout << tree[0] << "\n";
  }
  return 0;
}
