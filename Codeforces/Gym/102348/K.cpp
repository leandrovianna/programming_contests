// Codeforces Gym - K - Moonbound - 102348K - Southern and Volga Qualifier
#include <bits/stdc++.h>
using namespace std;

void print_op(int t, int x, int y, int b) {
  cout << t << " "
      << x << " "
      << y << " "
      << b << "\n";
}

int main() {
  int n;
  cin >> n;

  cout << 3 * ((n*n)/4) << "\n";
  for (int i = 1; i <= n; i += 2) {
    for (int j = n-1; j >= 1; j -= 2) {
      print_op(1, i, j, 1);
      print_op(1, i+1, j+1, 1);
      print_op(2, i, j, 2);
    }
  }
  return 0;
}
