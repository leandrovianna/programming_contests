// Lib - Memory Usage POSIX
#ifdef __linux__
#include <sys/time.h>
#include <sys/resource.h>
#endif

#include <bits/stdc++.h>
using namespace std;

int main() {
  const int N = 1 << 30;
  int *p = new int[N];

  for (int i = 0; i < N; i++) {
    p[i] = 10;
  }

  // should compile with -DMEM to define MEM
#ifdef __linux__
#ifdef MEM
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  cout << usage.ru_maxrss << "KB" << endl;
#endif
#endif

  delete p;
  return 0;
}
