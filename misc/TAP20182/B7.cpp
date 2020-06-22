// TAP 2018/2 - B7 - Braille
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int D = 110;
    int d;
    string num[D], s;
    cin >> d;

    for (int j = 0; j < d; j++) {
        num[j] = "";
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < d; j++) {
            cin >> s;
            num[j] += s;
        }
    }

    map<string, char> digit;
    digit[".***.."] = '0';
    digit["*....."] = '1';
    digit["*.*..."] = '2';
    digit["**...."] = '3';
    digit["**.*.."] = '4';
    digit["*..*.."] = '5';
    digit["***..."] = '6';
    digit["****.."] = '7';
    digit["*.**.."] = '8';
    digit[".**..."] = '9';

    string ans = "";
    for (int j = 0; j < d; j++) {
        ans += digit[num[j]];
    }

    cout << ans << endl;

    return 0;
}
