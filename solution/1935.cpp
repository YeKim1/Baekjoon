#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;


//void Ato1(string& s, int n) {
// 
// 
// ************** ���ڸ� ���� �� ���� ���� *******************
// 
// 
//	char* arr = new char[n];
//
//	char num;
//
//	for (int i = 0; i < n; i++) {
//		cin >> num;
//		arr[i] = num;
//	}
//
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] >= 'A' && s[i] <= 'Z') {
//			s[i] = arr[s[i] - 'A'];
//			cout << s << endl;
//		}
//	}
//
//}

int main() {
	int n, num;
	cin >> n;

	// 1) ���ĺ��� ���ڸ� ������ �� �����
	// 2) ���

	string s;
	cin >> s;

	double arr[26];

	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
	}


	stack<double> num_stack;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			double num1 = num_stack.top();
			num_stack.pop();
			double num2 = num_stack.top();
			num_stack.pop();

			num_stack.push(num2 + num1);
		}
		else if (s[i] == '-') {
			double num1 = num_stack.top();
			num_stack.pop();
			double num2 = num_stack.top();
			num_stack.pop();

			num_stack.push(num2 - num1);
		}
		else if (s[i] == '*') {
			double num1 = num_stack.top();
			num_stack.pop();
			double num2 = num_stack.top();
			num_stack.pop();

			num_stack.push(num2 * num1);
		}
		else if (s[i] == '/') {
			double num1 = num_stack.top();
			num_stack.pop();
			double num2 = num_stack.top();
			num_stack.pop();

			num_stack.push(num2 / num1);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			num_stack.push(arr[s[i] - 'A']);
		}

	}

	printf("%.2f", num_stack.top());


}