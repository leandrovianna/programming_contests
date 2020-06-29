// URI - Trocando de Mesa - 3109 
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int func[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;
  
  for (int i = 1; i <= n; i++) {
    func[i] = i;
  }

  for (int i = 0, e, a, b; i < q; i++) {
    cin >> e;
    if (e == 1) {
      cin >> a >> b;
      swap(func[a], func[b]);
    } else {
      cin >> a;
      b = a;
      int c = 0;
      while (func[b] != a) {
        b = func[b];
        c++;
      }
      cout << c << "\n";
    }
  }
  
  return 0;
}
