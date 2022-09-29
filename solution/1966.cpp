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

		while (true) { // m ���ʱ��� �ݺ�
			
			pair<int, int> max = make_pair(0, 0);
			for (int j = 0; j < q.size(); j++) {
				if (q.front().second > max.second) {
					max = q.front();
				}
				pair<int, int> temp = q.front();
				q.pop();
				q.push(temp);

			}

			if (max.first == m) { // max�� m�̸� m�� ��µ� ����
				count++;
				break;
			}
			else { 
				while (q.front() != max) { // max_index�� ã�� ������
					pair<int, int> p = q.front();
					q.pop();
					q.push(p);
				}
				q.pop(); // max_index�� ���
				count++;
			}



		}

		cout << count << endl;
	}
}