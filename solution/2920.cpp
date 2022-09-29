#include <iostream>
using namespace std;

int main() {
	int arr[8];
	int n;
	for (int i = 0; i < 8; i++) {
		cin >> n;
		arr[i] = n;
	}

	string res;

	for (int i = 1; i < 8; i++) {
		if (arr[i] < arr[i - 1]) break;
		if (i == 7) res = "ascending";
	}

	if (res != "ascending") {
		for (int i = 1; i < 8; i++) {
			if (arr[i] > arr[i - 1]) break;
			if (i == 7) res = "descending";
		}
	}

	if (res != "ascending" && res != "descending") {
		res = "mixed";
	}

	cout << res << endl;
	
	
}