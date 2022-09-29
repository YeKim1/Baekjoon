#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int graph[100][100];
bool visit[100][100] = { false };
int dis[100][100] = { 1 };

int X[4] = { 0,0,1,-1 };
int Y[4] = { 1,-1,0,0 };

int main() {
	int X_max, Y_max;
	string str;

	cin >> Y_max >> X_max;

	for (int Y = 0; Y < Y_max; Y++) {
		cin >> str;
		for (int X = 0; X < X_max; X++) {
			graph[X][Y] = str[X] - '0';
		}
	}
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visit[0][0] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nX = cur.first + X[i];
			int nY = cur.second + Y[i];
			if (nX >= 0 && nY >= 0 && nX < X_max && nY < Y_max && graph[nX][nY] == 1) {
				if (!visit[nX][nY]) {
					q.push(make_pair(nX, nY));
					visit[nX][nY] = true;
					dis[nX][nY] = dis[cur.first][cur.second] + 1;
				}
			}
		}
	}

	cout << dis[X_max - 1][Y_max - 1];

}