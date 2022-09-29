#include <iostream>
#include <vector>
using namespace std;

int graph[1001][1001];
bool visit[1001] = { false };

void dfs(vector<int>* graph, int start) {
	visit[start] = true;

	for (int i = 0; i < graph[start].size(); i++) {
		int temp = graph[start][i];
		if (visit[temp] == false) dfs(graph, temp);
	}
}

int main() {
	int n, m, u, v;
	cin >> n >> m;

	vector<int>* graph = new vector<int>[1001];

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(graph, i);
			count++;
		}
	}

	cout << count;

}