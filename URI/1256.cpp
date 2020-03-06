#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *next;
	
	Node(int key) : key(key), next(nullptr) {}
};

void free_table(Node *node) {
	if (node == nullptr)
		return;
	
	free_table(node->next);
	
	free(node);
}

const int M = 110;
Node *table[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t, c, m;
	
	cin >> t;
	while (t--) {
		cin >> m >> c;
		
		for (int id = 0; id < m; id++) {
			table[id] = nullptr;
		}
		
		for (int i = 0, x; i < c; i++) {
			cin >> x;
			
			int id = x % m;
			
			if (table[id] == nullptr) {
				table[id] = new Node(x);
			} else {
				Node *node = table[id];
	
				while (node->next != nullptr) {
					node = node->next;
				}
				
				node->next = new Node(x);
			}
		}
		
		for (int id = 0; id < m; id++) {
			cout << id << " -> ";
			Node *node = table[id];
			while (node != nullptr) {
				cout << node->key << " -> ";
				node = node->next;
			}
			cout << "\\" << "\n";
			
			free_table(table[id]);
		}
		
		if (t > 0)
			cout << "\n";
	}
	return 0;
}
