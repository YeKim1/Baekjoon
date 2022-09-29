#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, L, A;
	cin >> N >> L;

	int* A_arr = new int[N+1];
	A_arr[0] = -1;

	for (int i = 1; i < N + 1; i++) {
		cin >> A;
		A_arr[i] = A;
	}

	int* D_arr = new int[N + 1];
	D_arr[0] = -1;

	for (int i = 1; i < N + 1; i++) {
		priority_queue<int, vector<int>, greater<int>> q;
		if ((i - L + 1) > 0) {
			for (int j = i - L + 1; j <= i; j++) {
				q.push(A_arr[j]);
			}
		}
		else {
			for (int j = 1; j <= i; j++) {
				q.push(A_arr[j]);
			}
		}
		D_arr[i] = q.top();
	}

	for (int i = 1; i < N + 1; i++) {
		cout << D_arr[i] << " ";
	}


}