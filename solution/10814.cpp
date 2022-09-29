#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b) {
	if (a.first.first == b.first.first) { return a.second < b.second; }
	else return a.first < b.first;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, age;
	string name;
	
	cin >> N;

	vector<pair<pair<int, string>, int>> v;

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		v.push_back(make_pair(make_pair(age, name), i));
	}

	sort(v.begin(), v.end(), compare);

	for (auto& a : v) {
		cout << a.first.first << " " << a.first.second << "\n";
	}

}