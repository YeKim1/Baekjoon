#include <iostream>
using namespace std;

int main() {
	int n, temp;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 1; j <= arr[i]; j++) {
			if (arr[i] % j == 0) count++;
		}
		if (count == 2) ans++;
	}

	cout << ans << endl;
}