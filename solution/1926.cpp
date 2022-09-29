#include <iostream>
#include <vector>
using namespace std;

int graph[501][501];
bool visit[501][501];

int x[4] = {-1, 0, 1,0};
int y[4] = {0, 1, 0,-1};

bool isEmpty(int graph[501][501], int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] == 1) return false;
		}
		return true;
	}
}

int dfs(int graph[501][501], int start_x, int start_y) {
	int max = 1;
	visit[start_x][start_y] = true;

	for (int i = 0; i < 4; i++) {
		int move_x = start_x + x[i];
		int move_y = start_y + y[i];
		if (visit[move_x][move_y] == false && graph[move_x][move_y] == 1 && move_x <= 500 && move_y <= 500) {
			max += dfs(graph, move_x, move_y);
		}
	}

	return max;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, num;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> num;
			graph[i][j] = num;
		}
	}

	if (isEmpty(graph, n, m) == true) cout << 0 << "\n" << 0;
	else {
		int count = 0;
		int max_num = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (graph[i][j] == 1 && visit[i][j] == false) {
					count++;
					int temp = dfs(graph, i, j);
					if (temp > max_num) max_num = temp;
				}
			}
		}

		cout << count << "\n" << max_num;
	}
}