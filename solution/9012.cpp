#include <iostream>
#include <stack>
using namespace std;

int main() {


	string s;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		stack<char> stack;
		for (int j = 0; j < s.size(); j++) {	
			if (s[j] == '(') {
				stack.push(s[j]);
			}
			else {
				if (stack.empty()) {
					stack.push('f');
					break;
				}
				else stack.pop();
			}
		}

		if (stack.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
}