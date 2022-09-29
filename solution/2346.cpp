#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, M;
	cin >> N;

	int top_idx = 0;

	deque<pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		cin >> M;
		q.push_back(make_pair(i, M));
	}

	
}