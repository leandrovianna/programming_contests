// Codeforces - Permutation Game - 1003C
// Grundy Number
// Game description: 
/* A token is placed in one of the cells. They take 
 * alternating turns of moving the token around the board, 
 * with Alice moving first. The current player can move from 
 * cell i to cell j only if the following two conditions are satisfied:
     ** the number in the new cell j must be strictly larger than 
     ** the number in the old cell i (i.e. a[j] > a[i]), and
     ** the distance that the token travels during this turn 
     ** must be a multiple of the number in the old cell 
     (i.e. |i - j| mod a[i] == 0).
 * Whoever is unable to make a move, loses. 
 */
/* Note: for combining various games, make nim-sum (xor-sum) of
 * grundy numbers of each game. If this value is 0, first player
 * loses, otherwise first player win.
 */

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
