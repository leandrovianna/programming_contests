//Lib - Debug message for CF
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void debug(T value) {
#ifndef ONLINE_JUDGE
    cout << value << endl;
#endif
}

template <typename T, typename... Args>
void debug(T value, Args... args) {
#ifndef ONLINE_JUDGE
    cout << value;
    debug(args...);
#endif
}

int main() {
    debug("this message do not will appear in CF.");
    return 0;
}
