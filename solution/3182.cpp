#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, x;
	map<int, int> m;
	// <번호, 다음 번호>
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> x;
		m.insert(make_pair(i, x));
	}

	int max_i = 1; int max_v = 0;

	for (int i = 1; i <= N; i++) {
		int count = 0;
		int cur = i;
		int pre = i;
		while (count <= N) {
			pre = cur;
			cur = m.find(cur)->second;
			if (m.find(cur)->second == pre) break;
			count++;
		}

		if (max_v < count) {
			max_v = count;
			max_i = i;
		}
	}

	cout << max_i;





}