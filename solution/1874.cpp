#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	stack<int> stack;
	cin >> n;
	
	queue<int> q;
	vector<char> ans;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	for (int i = 0; i < n; i++) {
		cin >> m;

		if (stack.empty()) {

			while (!q.empty() && q.front() != m) {
				stack.push(q.front());
				ans.push_back('+');
				q.pop();
			}
			stack.push(q.front());
			ans.push_back('+');
			q.pop();


			stack.pop();
			ans.push_back('-');

		}
		else if (stack.top() > m) {
			ans.push_back('f');
			break;
		}
		else if (stack.top() < m) {

			while (q.front() != m) {
				stack.push(q.front());
				ans.push_back('+');
				q.pop();
			}
			stack.push(q.front());
			ans.push_back('+');
			q.pop();


			stack.pop();
			ans.push_back('-');

		}
		else { // °°À» ¶§
			stack.pop();
			ans.push_back('-');
		}
	}

	if (ans[ans.size() - 1] == 'f') {
		cout << "NO";
	}
	else {
		for (int i = 0;i<ans.size();i++) {
			cout << ans[i] << "\n";
		}
	}
}