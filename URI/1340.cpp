// URI - Eu posso adivinhar a estrutura de dados! - 1340
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    char op;

    while (cin >> n) {
        stack<int> st;
        queue<int> qu;
        priority_queue<int> pq;

        bool isStack = true,
             isQueue = true,
             isPQueue = true;

        for (int i = 0; i < n; i++) {
            cin >> op >> x;

            if (op == '1') {
                st.push(x);
                qu.push(x);
                pq.push(x);
            } else {
                if (isStack) {
                    if (st.top() != x) {
                        isStack = false;
                    } else {
                        st.pop();
                    }
                }

                if (isQueue) {
                    if (qu.front() != x) {
                        isQueue = false;
                    } else {
                        qu.pop();
                    }
                }

                if (isPQueue) {
                    if (pq.top() != x) {
                        isPQueue = false;
                    } else {
                        pq.pop();
                    }
                }
            }
        }

        int cnt = 0;
        if (isStack) cnt++;
        if (isQueue) cnt++;
        if (isPQueue) cnt++;

        if (cnt == 2 || cnt == 3) {
            cout << "not sure\n";
        } else if (cnt == 1) {
            if (isStack)
                cout << "stack\n";
            else if (isQueue)
                cout << "queue\n";
            else
                cout << "priority queue\n";
        } else {
            cout << "impossible\n";
        }
    }
    return 0;
}
