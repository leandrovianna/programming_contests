// Codeforces - Format - 101137F - NEERC Moscow Subregional 2016
#include <bits/stdc++.h>
using namespace std;

const int M = 300;
int order[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k = 0;
    order[' '] = k++;
    for (char ch = '0'; ch <= '9'; ch++) {
        order[(int) ch] = k++;
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        order[(int) ch] = k++;
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        order[(int) ch] = k++;
    }

    string s;
    getline(cin, s);

    set<char> ss;
    for (const auto &ch : s) {
        ss.insert(ch);
    }

    s = "";
    for (const auto &ch : ss) {
        s += ch;
    }

    string t = "";
    if (ss.count(' ') == 0)
        t += ' ';
    for (char ch = '0'; ch <= '9'; ch++) {
        if (ss.count(ch) == 0)
            t += ch;
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ss.count(ch) == 0)
            t += ch;
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ss.count(ch) == 0)
            t += ch;
    }

    vector<pair<char, char>> inter;

    inter.push_back({s[0], s[0]});

    for (int i = 1, n = s.size(); i < n; i++) {
        char curr = inter.back().second;

        if (order[(int) curr] + 1 == order[(int) s[i]]) {
            inter.back().second = s[i];
        } else {
            inter.push_back({s[i], s[i]});
        }
    }

    vector<pair<char, char>> inter2;

    if (!t.empty()) {
        inter2.push_back({t[0], t[0]});
    }

    for (int i = 1, n = t.size(); i < n; i++) {
        char curr = inter2.back().second;

        if (order[(int) curr] + 1 == order[(int) t[i]]) {
            inter2.back().second = t[i];
        } else {
            inter2.push_back({t[i], t[i]});
        }
    }

    string ans1 = "", ans2 = "";

    for (const auto &p : inter) {
        if (order[(int) p.second] - order[(int) p.first] + 1 <= 2) {
            ans1 += p.first;
            if (p.first != p.second)
                ans1 += p.second;
        } else {
            ans1 += p.first;
            ans1 += '-';
            ans1 += p.second;
        }
    }

    for (int i = 0, n = ans1.size(); i < n-1; i++) {
        if (ans1[i+1] != '-') continue;

        if (ans1[i] == '0')
            ans1[i] = '!';
        else if (ans1[i] == 'A')
            ans1[i] = ':';
        else if (ans1[i] == 'a')
            ans1[i] = '[';
    }

    ans2 += '^';
    for (const auto &p : inter2) {
        if (order[(int) p.second] - order[(int) p.first] + 1 <= 2) {
            ans2 += p.first;
            if (p.first != p.second)
                ans2 += p.second;
        } else {
            ans2 += p.first;
            ans2 += '-';
            ans2 += p.second;
        }
    }

    for (int i = 0, n = ans2.size(); i < n-1; i++) {
        if (ans2[i+1] != '-') continue;

        if (ans2[i] == '0')
            ans2[i] = '!';
        else if (ans2[i] == 'A')
            ans2[i] = ':';
        else if (ans2[i] == 'a')
            ans2[i] = '[';
    }

    cout << "%[";
    if (t.empty())
        cout << "^!";
    else if (ans1.size() < ans2.size())
        cout << ans1;
    else if (ans1.size() > ans2.size())
        cout << ans2;
    else
        cout << (ans1 < ans2 ? ans1 : ans2);
    cout << "]\n";

    return 0;
}
