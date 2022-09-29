#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {

	int T, n, m, num;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;

		queue<pair<int, int>> q;

		for (int j = 0; j < n; j++) {
			cin >> num;
			q.push(make_pair(j, num));
		}

		int count = 0;

		while (true) { // m 차례까지 반복
			
			pair<int, int> max = make_pair(0, 0);
			for (int j = 0; j < q.size(); j++) {
				if (q.front().second > max.second) {
					max = q.front();
				}
				pair<int, int> temp = q.front();
				q.pop();
				q.push(temp);

			}

			if (max.first == m) { // max가 m이면 m이 출력될 차례
				count++;
				break;
			}
			else { 
				while (q.front() != max) { // max_index를 찾을 때까지
					pair<int, int> p = q.front();
					q.pop();
					q.push(p);
				}
				q.pop(); // max_index면 출력
				count++;
			}



		}

		cout << count << endl;
	}
}