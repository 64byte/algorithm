/*
https://www.acmicpc.net/problem/15812

재귀 + bfs 문제

빈 공간(마을이 아닌 곳) 중에 2개의 좌표를 고른다.

2개를 고르면 bfs로 체크함

여기선 마을에 독이 몇 번 퍼졌는 지만 체크하고 끝나면 넘어가면 된다.

좌표를 골라가면서 bfs할 때, 이전 값이 독이 퍼지는 시간보다 크진다면 (같다면) 그냥 t를 반환한다 (가지치기)
(이전에 골랐던 2개의 좌표로 5번만에 독을 퍼트릴 수 있다면, 현재 고른 2개 좌표를 가지고 독을 퍼트리는데 5가 넘을 때 더 이상 진행할 필요가 없다. 어차피 최적이 아니니까)

*/

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <stack>
#include <tuple>

using namespace std;

int N, M;

char m[21][21];
bool visited[21][21];

int ans = 987654321;

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { -1, 1, 0, 0 };

int onesCount = 0;

int bfs(vector<pair<int, int>>& pairs, int oneCount) {

	memset(visited, 0, sizeof(visited));

	queue<tuple<int, int, int>> q;

	for (const auto& p : pairs) {
		visited[p.first][p.second] = true;
		q.push({ p.first, p.second, 0 });
	}

	int totalCount = 0;

	while (!q.empty()) {

		auto node = q.front();
		q.pop();

		int y = get<0>(node);
		int x = get<1>(node);
		int t = get<2>(node);

		if (totalCount == onesCount) {
			return t;
		}

		if (t >= ans) {
			return t;
		}

		for (int i = 0; i < 4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
				continue;
			}

			if (visited[next_y][next_x] == false) {
				visited[next_y][next_x] = true;
				if (m[next_y][next_x] == '1') {
					totalCount++;
				}

				q.push({ next_y, next_x, t + 1 });
			}
		}

	}

	return 987654321;
}

void dfs(int i, vector<pair<int, int>>& zeros, vector<pair<int, int>>& g) {

	//if (i >= zeros.size()) {
	if (g.size() == 2) {
		ans = min(ans, bfs(g, onesCount));
		return;
	}

	if (i >= zeros.size()) {
		return;
	}

	g.push_back(zeros[i]);
	dfs(i + 1, zeros, g);
	g.pop_back();

	dfs(i + 1, zeros, g);

}

int main(void) {

	cin >> N >> M;

	vector<pair<int, int>> zeros;
	vector<pair<int, int>> ones;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> m[i][j];
			if (m[i][j] == '0') {
				zeros.push_back({ i, j });
			}
			else {
				ones.push_back({ i, j });
			}
		}
	}

	onesCount = ones.size();

	vector<pair<int, int>> g;
	dfs(0, zeros, g);

	cout << (ans+1) << endl;
}
