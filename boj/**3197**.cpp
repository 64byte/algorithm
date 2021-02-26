/*
https://www.acmicpc.net/problem/3197

복습 필요한 문제

bfs로 녹는 날짜에 대한 맵을 새로 만든 것까진 좋았으나

다음 스텝에서 생각을 많이 했음.

0 ~ max day 사이에 이분탐색으로 최적의 해를 찾는다. (x 날짜에 접근할 수 없으면 x~max day까지는 어쨌든 접근 못하니까)

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
#include <map>
#include <string>
#include <stack>
#include <tuple>

using namespace std;

using ll = long long;

const ll INF = 987654321;

char m[1501][1501];
long long dist[1501][1501];
bool visited[1501][1501];

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { -1, 1, 0, 0 };

bool bfs(int start_y, int start_x, int to_y, int to_x, int N, int M, int day) {

	queue<tuple<int, int ,int>> q;
	memset(visited, false, sizeof(visited));

	q.push({ start_y, start_x, 0 });
	visited[start_y][start_x] = true;

	while (!q.empty()) {
		auto node = q.front();
		int y = get<0>(node);
		int x = get<1>(node);
		int d = get<2>(node);
		q.pop();

		if (y == to_y && x == to_x) {
			return true;
		}

		for (int i = 0; i < 4; ++i) {
			int next_y = dy[i] + y;
			int next_x = dx[i] + x;
			int next_d = d + 1;

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
				continue;
			}

			if (!visited[next_y][next_x] && dist[next_y][next_x] <= day) {
				visited[next_y][next_x] = true;
				q.push({ next_y, next_x, next_d });
			}


		}


	}

	return false;
}

int main() {

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> xy;

	vector<pair<int, int>> swan;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> m[i][j];
			if (m[i][j] == '.') {
				xy.push_back({ i, j });
			}
			else if (m[i][j] == 'L') {
				swan.push_back({ i, j });
			}
		}
	}

	memset(dist, -1, sizeof(dist));

	queue<tuple<int, int, int>> q;
	for (const auto& x : xy) {
		dist[x.first][x.second] = 0;
		q.push({ x.first, x.second, 0 });
	}

	for (const auto& x : swan) {
		dist[x.first][x.second] = 0;
		q.push({ x.first, x.second, 0 });
	}

	long long maxDay = 0;

	while (!q.empty()) {
		auto node = q.front();
		q.pop();

		int y = get<0>(node);
		int x = get<1>(node);

		for (int i = 0; i < 4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			
			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
				continue;
			}

			if (m[next_y][next_x] == 'X' && dist[next_y][next_x] == -1) {
				dist[next_y][next_x] = dist[y][x] + 1;
				q.push({ next_y, next_x, 0 });

				maxDay = max(maxDay, dist[next_y][next_x]);
			}

		}

	}

	ll l = 0;
	ll h = maxDay;

	ll ans = 0;
	while (l <= h) {
		ll m = (l + h) / 2;

		if (bfs(swan[0].first, swan[0].second, swan[1].first, swan[1].second, N, M, m)) {
			h = m - 1;
		}
		else {
			l = m + 1;
		}

	}

	cout << l << endl;
}
