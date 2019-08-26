// Codeforces - Increasing Subsequence (easy version) - 1157C1
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

    if (a[left] < a[right]) {
        top = a[left];
        answer += "L";
        left++;
    } else {
        top = a[right];
        answer += "R";
        right--;
    }

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
        } else {
            if (top < a[right]) {
                top = a[right];
                answer += "R";
                right--;
            } else {
                top = a[left];
                answer += "L";
                left++;
            }
        }
    }

    cout << answer.size() << "\n" << answer << "\n";
    
    return 0;
}
