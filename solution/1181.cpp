#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;

	cin >> N;

	map<string, int> m[50];

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m[s.size() - 1].insert(make_pair(s, s.size()));
	}

	for (int i = 0; i < 50; i++) {
		if (!m[i].empty()) {
			for (map<string, int>::iterator iter = m[i].begin(); iter != m[i].end(); iter++) {
				cout << iter->first << endl;
			}
		}
	}
}