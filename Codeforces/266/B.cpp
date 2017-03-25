#include <iostream>
#include <cstring>
using namespace std;

int main() {
	const int N = 50;
	char queue[N+1];
	int n, t;
	
	cin >> n >> t;
	cin >> queue;

	while (t-- > 0) {
		for (int i = 1; i < strlen(queue); i++) {
			if (queue[i-1] == 'B' && queue[i] == 'G') {
				char c = queue[i-1];
				queue[i-1] = queue[i];
				queue[i] = c;
				i++;
			}
		}
	}

	cout << queue << endl;
	return 0;
}
