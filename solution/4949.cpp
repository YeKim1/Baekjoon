#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {

		string s = "";
		string temp = "";

		getline(cin, s);

		if (s == ".") break;

		stack<char> stack;

		bool ans = true;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') stack.push(s[i]);
			else if (s[i] == ')') {
				if (stack.empty()) {
					ans = false;
					break;
				}
				else if (stack.top() == '(') stack.pop();
				else {
					ans = false;
					break;
				}
			}
			else if (s[i] == ']') {
				if (stack.empty()) {
					ans = false;
					break;
				}
				else if (stack.top() == '[') stack.pop();
				else {
					ans = false;
					break;
				}
			}
		}

		if (ans == true && stack.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}