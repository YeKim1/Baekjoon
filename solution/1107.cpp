#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int cur = 100;
	int N, M, C;
	cin >> N;
	cin >> M;

	vector<int> v;
	bool break_bt[10];
	for (int i = 0; i < 10; i++) {
		break_bt[i] = true;
	}
	for (int i = 0; i < M; i++) {
		cin >> C;
		break_bt[C] = false;
	}

	int cnt = 0;

	if (cur != N) {
		// 1. ���峪�� ���� ��ư�� �̿��� ���� ������ ä�η� �̵�

		int digits = to_string(N).length();
		string cur_str = "";

		int plus_cnt{ 0 }, minus_cnt{ 0 };
		for (int i = 0; i < digits; i++) {
			int plus_cur = to_string(N)[i] - '0';
			// ��ư�� ���峵����
			while (!break_bt[plus_cur]) {
				plus_cur++;
				plus_cnt++;
				if (plus_cur == 10) {
					plus_cnt = 10;
					break;
				}
			}
			int minus_cur = to_string(N)[i] - '0';
			while (!break_bt[minus_cur]) {
				minus_cur--;
				minus_cnt++;
				if (minus_cur == -1) {
					minus_cnt = 10;
					break;
				}
			}

			if (plus_cnt < minus_cnt) cur_str += to_string(plus_cur);
			else cur_str += to_string(minus_cur);

			cnt++;
		}
		// 2. + - ��ư�� �̿��� �ش� ä�η� �̵�

		cur = stoi(cur_str);

		if (cur < N) {
			while (cur != N) {
				cnt++;
				cur++;
			}
		}
		else {
			while (cur != N) {
				cnt++;
				cur--;
			}
		}
	}

	cout << cnt;


}