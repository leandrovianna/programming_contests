#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
int n;
int a[N];
int memo[N];

int calculateMex(unordered_set<int> set) { 
    int mex = 0; 
  
    while (set.find(mex) != set.end()) 
        mex++; 
  
    return mex; 
} 
  
int calculateGrundy(int i) { 
    if (memo[i] != -1)
        return memo[i];

    if (a[i] == n) 
        return 0; 
  
    unordered_set<int> set;
  
    for (int j = i + a[i]; j < n; j += a[i]) {
        if (a[j] > a[i])
            set.insert(calculateGrundy(j)); 
    }

    for (int j = i - a[i]; j >= 0; j -= a[i]) {
        if (a[j] > a[i]) {
            set.insert(calculateGrundy(j)); 
        }
    }
  
    return memo[i] = calculateMex(set); 
} 

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; i++) {
        cout << (calculateGrundy(i) > 0 ? "A" : "B");
    }
    cout << "\n";
    return 0;
}
