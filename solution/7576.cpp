#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int graph[1000][1000];
int dis[1000][1000] = { 0 };
int X[4] = { 1,-1,0,0 };
int Y[4] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M, num;
	cin >> M >> N;

	for (int i = 0; i < N; i++) { // ����
		for (int j = 0; j < M; j++) { // ����
			cin >> num;
			graph[j][i] = num;
		}
	}

	queue<pair<int, int>> q;
	
	// start ��ǥ ã��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[j][i] == 1) {
				q.push(make_pair(j, i));
			}
		}
	}

	int day = 0;

	// �����¿� Ž��
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nX = cur.X + X[i];
			int nY = cur.Y + Y[i];
			if (nX >= 0 && nX < M && nY >= 0 && nY < N) {
				if (graph[nX][nY] == 0) {
					q.push(make_pair(nX, nY));
					graph[nX][nY] = 1;

					// ��¥ �Է�
					dis[nX][nY] = dis[cur.X][cur.Y] + 1;

					// ���� ��¥ ����
					day = max(dis[nX][nY], day);
				}
			}
		}
	}

	// �� ���� �丶�� üũ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[j][i] == 0) {
				day = -1;
				break;
			}
		}
	}

	cout << day;

}