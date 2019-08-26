// Codeforces - Increasing Subsequence (hard version) - 1157C2
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = n-1;
    int top = 0;
    string answer = "";

    while (left <= right && (top < a[left] || top < a[right])) {
        if (a[left] < a[right]) {
            if (top < a[left]) {
                top = a[left];
                answer += "L";
                left++;
            } else {
                top = a[right];
                answer += "R";
                right--;
            }
        } else if (a[left] > a[right]) {
            if (top < a[right]) {
                top = a[right];
                answer += "R";
                right--;
            } else {
                top = a[left];
                answer += "L";
                left++;
            }
        } else {
            int size1 = 1, size2 = 1;
            int t = a[left];
            for (int i = left+1; i < right; i++) {
                if (t < a[i]) {
                    size1++;
                    t = a[i];
                } else {
                    break;
                }
            }

            t = a[right];
            for (int i = right-1; i > left; i--) {
                if (t < a[i]) {
                    size2++;
                    t = a[i];
                } else {
                    break;
                }
            }

            if (size1 > size2) {
                top = a[left];
                answer += "L";
                left++;
            } else {
                top = a[right];
                answer += "R";
                right--;
            }
        }
    }

    cout << answer.size() << "\n" << answer << "\n";
    
    return 0;
}
