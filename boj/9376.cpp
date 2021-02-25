/*
https://www.acmicpc.net/problem/9376

다익스트라 문제 #는 가중치 1로 두고 푼다

상근이 위치, 죄수 2명의 위치에서 다익스트라로 탐색해서

위치를 다 더 해줌, #를 뚫었을 경우 중복으로 뚫으므로 -2를 해준다. (총 3명)

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

const long long INF = 987654321;

char m[103][103];
long long dist[103][103][3];

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { -1, 1, 0, 0 };

void bfs(int start_y, int start_x, int N, int M, int k) {
	priority_queue<pair<pair<int, int>, long long>> pq;

	int aN = N + 1;
	int aM = M + 1;

	dist[start_y][start_x][k] = 0;
	pq.push({ { start_y, start_x }, 0 });

	while (!pq.empty()) {
		auto node = pq.top().first;
		int y = node.first;
		int x = node.second;
		long long d = -pq.top().second;
		pq.pop();

		if (m[y][x] == '*')
			continue;


		for (int i = 0; i < 4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			long long next_d = d + (m[next_y][next_x] == '#' ? 1 : 0);

			if (next_y < 0 || next_y > aN || next_x < 0 || next_x > aM) {
				continue;
			}

			if (m[next_y][next_x] == '*') {
				continue;
			}

			if (dist[next_y][next_x][k] > next_d) {
				dist[next_y][next_x][k] = next_d;
				pq.push({ {next_y, next_x }, -next_d });
			}

			if (m[next_y][next_x] == '$' && dist[next_y][next_x][k] > d) {
				dist[next_y][next_x][k] = d;
				pq.push({ {next_y, next_x }, -next_d });
			}

		}

	}

}

int main(void) {

	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	int t = 0;

	cin >> t;

		int N, M;
		int aN, aM;
		vector<pair<int, int>> v;
	while (t--) {

		cin >> N >> M;
		v.clear();

		aN = N + 2;
		aM = M + 2;

		for (int i = 0; i <= aN; ++i) {
			for (int j = 0; j <= aM; ++j) {
				m[i][j] = '.';
			}
		}

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				cin >> m[i][j];

				if (m[i][j] == '$') {
					v.push_back({ i, j });
				}
			}
		}

		for (int i = 0; i <= aN; ++i) {
			for (int j = 0; j <= aM; ++j) {
				for (int k = 0; k < 3; ++k) {
					dist[i][j][k] = INF;
				}
			}
		}


		bfs(0, 0, N, M, 0);
		bfs(v[0].first, v[0].second, N, M, 1);
		bfs(v[1].first, v[1].second, N, M, 2);


		long long sum = 0;
		long long  ans = INF;
		for (int i = 0; i <= aN; ++i) {
			for (int j = 0; j <= aM; ++j) {
				if (m[i][j] == '*') {
					continue;
				}

				sum = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
				if (m[i][j] == '#')
					sum -= 2;

				ans = min(ans, sum);
			}
		}


		cout << ans << endl;

	}

}
