#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isNum(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]) == 0) return false;
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M;

	cin >> N >> M;

	map<int, string> dogam_num;
	map<string, int> dogam_name;

	string name;
	for (int i = 1; i <= N; i++) {
		cin >> name;
		dogam_num.insert(make_pair(i, name));
		dogam_name.insert(make_pair(name, i));
	}

	string question;
	for (int i = 0; i < M; i++) {
		cin >> question;
		
		if (isNum(question)) {
			cout << dogam_num[(stoi(question))] << "\n";
		}
		else {
			cout << dogam_name[question] << "\n";
		}
	}

}