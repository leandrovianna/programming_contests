// Codeforces - All the Vowels Please - 1166B Div2
#include <bits/stdc++.h>
using namespace std;

const char vowels[] = {'a', 'e', 'i', 'o', 'u'};

const string lines[] = {
    "aeiou",
    "uaeio",
    "ouaei",
    "iouae",
    "eioua"
};

int main() {
    int k;
    cin >> k;

    string answer = "-1";
    for (int i = 5; i * i <= k; i++) {
        if (k % i == 0) {
            int n = i;
            int m = k / i;
            if (m >= 5) {
                answer = "";
                for (int j = 0; j < n; j++) {
                    if (j < 5) {
                        answer += lines[j];
                    } else {
                        answer += "aeiou";
                    }

                    for (int l = 5; l < m; l++) {
                        answer += vowels[j % 5];
                    }

                }
                break;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
