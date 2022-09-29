#include <iostream>
using namespace std;

int main() {
	int ans = 0;
	int n;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		ans += (n * n);
	}
	cout << ans % 10;
}