// Codeforces Gym - Gnoll Hypothesis - 102500G
#include <bits/stdc++.h>
using namespace std;

const int N = 510;
double p[N];
int n, k;

bool choosen[N];
double r[N];
void comb(int i, int j) {
  if (i == n) {
    for (int i = 0; i < n; i++) {
      if (!choosen[i]) {
        j = (i+1) % n;
      }
    }
    return;
  }

  choosen[i] = true;
  comb(i+1, j+1);

  choosen[i] = false;
  comb(i+1, j);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  return 0;
}
