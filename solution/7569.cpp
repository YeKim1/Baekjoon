#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int graph[100][100][100];
int dis[100][100][100] = { 0 };

int X[6] = { 1,-1,0,0,0,0 };
int Y[6] = { 0,0,1,-1,0,0 };
int H[6] = { 0,0,0,0,1,-1 };

int main() {
	int X_max, Y_max, H_max, num;

	cin >> X_max >> Y_max >> H_max;

	for (int H = 0; H < H_max; H++) {
		for (int Y = 0; Y < Y_max; Y++) {
			for (int X = 0; X < X_max; X++) {
				cin >> num;
				graph[X][Y][H] = num;
			}
		}
	}

	queue<pair<pair<int, int>, int>> q;

	// 익은 토마토 큐에 push
	for (int H = 0; H < H_max; H++) {
		for (int Y = 0; Y < Y_max; Y++) {
			for (int X = 0; X < X_max; X++) {
				if (graph[X][Y][H] == 1) q.push(make_pair(make_pair(X, Y), H));
			}
		}
	}

	int day = 0;

	//bfs
	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nX = cur.first.first + X[i];
			int nY = cur.first.second + Y[i];
			int nH = cur.second + H[i];

			if (
				nX >= 0 && nY >= 0 && nH >= 0 &&
				nX < X_max && nY < Y_max && nH < H_max &&
				graph[nX][nY][nH] == 0
				)
			{
				q.push(make_pair(make_pair(nX, nY), nH));
				graph[nX][nY][nH] = 1;
				dis[nX][nY][nH] = dis[cur.first.first][cur.first.second][cur.second] + 1;
				day = max(day, dis[nX][nY][nH]);
			}
		}
	}

	for (int H = 0; H < H_max; H++) {
		for (int Y = 0; Y < Y_max; Y++) {
			for (int X = 0; X < X_max; X++) {
				if (graph[X][Y][H] == 0) {
					day = -1;
					break;
				}
			}
		}
	}

	cout << day;

}