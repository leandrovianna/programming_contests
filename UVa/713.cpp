//UVa - Adding Reversed Numbers - UVA 713
#include <bits/stdc++.h>
using namespace std;

const int D = 210;
const int DELIM = 13;

void input(int num[]) {
    string inp;
    cin >> inp;
    int i = 0;
    for (const auto &ch : inp) {
        num[i] = ch - '0';
        i++;
    }
    num[i] = DELIM;
}

void print(int num[]) {
    int i = 0;
    while (num[i] != DELIM) {
        cout << num[i];
        i++;
    }
}

void reverse(int num[]) {
    int num2[D];
    int i = 0;
    while (num[i] != DELIM) {
        num2[i] = num[i];
        i++;
    }

    int j = i-1;
    while (num2[j] == 0) {
        j--;
    }

    num[j+1] = DELIM;
    for (int k = 0; j >= 0; k++, j--) {
        num[k] = num2[j];
    }
}

void sum(int n1[], int n2[], int ans[]) {
    int i = 0;
    while (n1[i] != DELIM) {
        i++;
    }
    int j = 0;
    while (n2[j] != DELIM) {
        j++;
    }

    int carry = 0, k = 0;
    i--;
    j--;
    while (i >= 0 || j >= 0 || carry > 0) {
        int v = carry;

        if (i >= 0) {
            v += n1[i];
            i--;
        }

        if (j >= 0) {
            v += n2[j];
            j--;
        }

        if (v >= 10) {
            ans[k] = v % 10;
            carry = 1;
        } else {
            ans[k] = v;
            carry = 0;
        }

        k++;
    }
    ans[k] = DELIM;

    reverse(ans);
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int n1[D], n2[D], n3[D]; // big numbers

    while (n--) {
        input(n1);
        input(n2);

        reverse(n1);
        reverse(n2);

        sum(n1, n2, n3);

        reverse(n3);

        print(n3);
        cout << endl;
    }

    return 0;
}
