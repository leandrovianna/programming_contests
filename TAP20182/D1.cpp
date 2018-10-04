// TAP 2018/2 - Koosbanian Calculations - D1
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> v;
    string tmp;

    size_t pos = -1;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == delimiter) {
            tmp = str.substr(pos+1, i - pos - 1);
            v.push_back(tmp);
            pos = i;
        }
    }

    if (pos < str.size()-1) {
        v.push_back(str.substr(pos+1));
    }

    return v;
}

int64_t value(char c) {
    if (c >= 'A')
        return 10 + (c - 'A');
    else
        return c - '0';
}

int64_t convert(string num) {
    int64_t n = 0, x = 1;
    reverse(num.begin(), num.end());
    for (const auto &ch : num) {
        n += value(ch) * x;
        x *= 13;
    }

    return n;
}

int64_t calc(vector<string> &tokens, int l, int r) {
    if (l == r) {
        return convert(tokens[l]);
    }

    for (int i = r-1; i >= l+1; i--) {
        if (tokens[i] == "+") {
            return calc(tokens, l, i-1) + calc(tokens, i+1, r);
        }
        if (tokens[i] == "-") {
            return calc(tokens, l, i-1) - calc(tokens, i+1, r);
        }
    }

    for (int i = r-1; i >= l+1; i--) {
        if (tokens[i] == "/") {
            return calc(tokens, l, i-1) / calc(tokens, i+1, r);
        }
        if (tokens[i] == "*") {
            return calc(tokens, l, i-1) * calc(tokens, i+1, r);
        }
    }

    return 0;
}

int main() {
    string expr;
    
    getline(cin, expr);

    vector<string> tokens = split(expr, ' ');
    tokens.pop_back();

    cout << calc(tokens, 0, tokens.size()-1) << endl;
    return 0;
}
