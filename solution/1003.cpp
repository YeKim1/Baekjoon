#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T, N;

	cin >> T;

	// f(N) = f(N-1) + N

	for (int i = 0; i < T; i++) {
		cin >> N;
		
		// first: 0 호출 second: 1 호출
		vector<pair<int,int>> DF(N + 1);

		DF[0] = make_pair(1, 0);
		DF[1] = make_pair(0, 1);

		for (int j = 2; j <= N; j++) {
			DF[j].first = DF[j - 1].first + DF[j - 2].first;
			DF[j].second = DF[j - 1].second + DF[j - 2].second;
		}

		cout << DF[N].first << " " << DF[N].second << "\n";
	}
}