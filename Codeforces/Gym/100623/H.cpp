// Codeforces - Gym - 100623H
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("holes.in");
    ofstream fout("holes.out");

    int h;
    fin >> h;

    if (h == 0)
        fout << "1\n";
    else if (h == 1)
        fout << "0\n";
    else {
        if (h & 1)
            fout << "4";

        fout << string(h / 2, '8');
        fout << "\n";
    }
    return 0;
}
