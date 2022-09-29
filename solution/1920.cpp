#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool BinarySearch(vector<int>& v, int k) {

	int low = 0;
	int high = v.size() - 1;
	

	while (low <= high) {
		int mid = (low + high) / 2;
		if (v[mid] == k) return true;
		
		if (v[mid] > k) {
			high = mid - 1;
		}
		else if (v[mid] < k) {
			low = mid + 1;
		}
	}

	return false;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, num;
	cin >> N;

	vector<int> v;


	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		
		if (BinarySearch(v, num)) cout << "1\n";
		else cout << "0\n";

	}

	
}