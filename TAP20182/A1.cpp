// TAP 2018/2 - A1 - The Name Game
#include <bits/stdc++.h>
using namespace std;

int main() {
    string name;

    cin >> name;

    cout << name << ", " << name << ", " << "bo-";
    if (name[0] != 'B')
        cout << "b";
    cout << name.substr(1) << "\n";

    cout << "Banana-fana fo-";
    if (name[0] != 'F')
        cout << "f";
    cout << name.substr(1) << "\n";

    cout << "Fee-fi-mo-";
    if (name[0] != 'M')
        cout << "m";
    cout << name.substr(1) << "\n";

    cout << name << "!\n";

    return 0;
}
