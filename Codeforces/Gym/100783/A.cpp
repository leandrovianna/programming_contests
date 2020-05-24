// Codeforces Gym - GREAT+SWERC=PORTO
#include <bits/stdc++.h>
using namespace std;

const int N = 15;
string words[N];
int64_t numbers[N];

const int E = 30;
bool mark[E];
int value[E];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> words[i];

        for (const auto &ch : words[i]) {
            mark[ch - 'A'] = true;
        }
    }

    vector<int> letters;
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int e = 0; e < 26; e++) {
        if (mark[e])
            letters.push_back(e);
    }

    int answer = 0;
    int skip_count = 1;
    const int qtd_letters = letters.size();
    for (int i = 1; i <= 10 - qtd_letters; i++) {
        skip_count *= i;
    }

    int t = 0;
    do {
        if (t % skip_count != 0) {
            t++;
            continue;
        }

        for (int i = 0, sz = letters.size(); i < sz; i++) {
            value[letters[i]] = digits[i];
        }

        bool invalid = false;
        for (int i = 0; i < n; i++) {
            if (value[words[i][0] - 'A'] == 0) {
                invalid = true;
                break;
            }
        }

        if (invalid)
            continue;

        for (int i = 0; i < n; i++) {
            numbers[i] = 0;

            for (const auto &ch : words[i]) {
                numbers[i] = numbers[i] * 10 + value[ch - 'A'];
            }
        }

        int64_t sum = 0;
        for (int i = 0; i < n-1; i++) {
            sum += numbers[i];
        }

        if (sum == numbers[n-1]) {
            /*
            cout << "*" << t << " ";
            for (int i = 0, sz = letters.size(); i < sz; i++) {
                cout << static_cast<char>(letters[i] + 'A')
                    << ": " << digits[i] << ", ";
            }
            cout << endl;
            */

            answer++;
        }

        t++;
    } while (next_permutation(digits, digits+10));

    cout << answer << "\n";

    return 0;
}
