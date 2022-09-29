#include <iostream>
#include <set>
using namespace std;

int graph[26][26];
bool visit[26][26] = { false };
int x[4] = { 0 ,1 ,0 , -1 };
int y[4] = { -1, 0, 1, 0 };

int dfs(int graph[26][26], int start_x, int start_y) {
	int count = 1;
	visit[start_x][start_y] = true;

	for (int i = 0; i < 4; i++) {
		int move_x = start_x + x[i];
		int move_y = start_y + y[i];
		if (move_x <= 25 && move_y <= 25 && visit[move_x][move_y] == false && graph[move_x][move_y] == 1) {
			count += dfs(graph, move_x, move_y);
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, num;

	cin >> n;

	string str;
	// 한 글자씩 잘라서 입력하기!!
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			graph[i][j + 1] = str[j] - '0';
		}
	}

	int count = 0;
	multiset<int> count_num;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == false && graph[i][j] == 1) {
				count++;
				int temp = dfs(graph, i, j);
				count_num.insert(temp);
			}
		}
	}

	cout << count << "\n";

	for (multiset<int>::iterator iter = count_num.begin(); iter != count_num.end(); iter++) {
		cout << *iter << "\n";
	}
}