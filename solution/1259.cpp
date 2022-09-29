#include <iostream>
using namespace std;

string reverse(string s) {
	string ans = "";
	
	for (int i = s.length() - 1; i >= 0; i--) {
		ans += s[i];
	}

	return ans;

}

int main() {

	string s;

	while (true) {
		cin >> s;

		if (s == "0") break;

		int len = s.length();

		if (len == 1) cout << "yes\n";

		else if (len == 2) {
			if (s[0] == s[1]) cout << "yes\n";
			else cout << "no\n";
		}

		else if (len == 3) {
			if (s[0] == s[2]) cout << "yes\n";
			else cout << "no\n";
		}

		else if (len == 4) {
			if (s[0] == s[3] && s[1] == s[2]) cout << "yes\n";
			else cout << "no\n";
		}

		else if (len == 5) {
			if (s[0] == s[4] && s[1] == s[3]) cout << "yes\n";
			else cout << "no\n";
		}
	}
}