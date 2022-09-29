#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	// ���� Ƚ���� �����ϴ� �迭 ����
	vector<int> DP(N + 1);

	// 1�� ��� ���� Ƚ���� 0ȸ
	DP[1] = 0;
	
	// Bottom-Up ���
	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
		
	}

	cout << DP[N];
}
