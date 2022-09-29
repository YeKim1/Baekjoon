#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int T, k, num;
	string str;

	cin >> T;

	for (int i = 0; i < T; i++) {
		
		priority_queue<int> min_pq;
		priority_queue<int, vector<int>, greater<int>> max_pq;
		
		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> str >> k;

			if (str == "I") {
				pq.push(k);
			}
			else if (str == "D") {
				if (!pq.empty()) {
					if (k == -1) {
						pq.pop();
					}
					else {
						pq.
					}
				}
			}
		}

		if (dq.empty()) cout << "EMPTY\n";
		else {
			cout << dq.back() << " " << dq.front() << "\n";
		}

	}
}