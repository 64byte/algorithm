/*
https://www.acmicpc.net/problem/18512

배양액을 뿌릴 수 있는 땅 e
녹색 배양액 g
빨간색 배양액 r

eCg * (e-g)Cr

위 식의 조합을 다 구한 다음, bfs한다

green, red 같이 bfs하면서 방문할 좌표에서 다른 배양액이 먼저 방문되었다면, 해당 사례는 꽃을 피울 수 있으므로 다음 좌표로 넘어감

가짓수는 (green+red)가 나오므로 2를 나눠준다.

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

int N, M, G, R;

char m[51][51];

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { 1, -1, 0, 0 };

vector<pair<int, int>> canSeed;

int ans = 0;

int visited[51][51][2] = { 0 };

void dfs(int i, int g, int r, vector<pair<pair<int, int>, bool>>& seed) {

	if (g == 0 && r == 0) {
		int canFlower = 0;

		queue<pair<pair<int, int>, bool>> q;

		memset(visited, -1, sizeof(visited));

		for (const auto& s : seed) {
			q.push(s);
			visited[s.first.first][s.first.second][s.second] = 0;
		}

		while (!q.empty()) {
			const auto& node = q.front();
			int y = node.first.first;
			int x = node.first.second;
			bool greenOrRed = node.second;
			q.pop();

			if (visited[y][x][greenOrRed] == visited[y][x][!greenOrRed]) {
				visited[y][x][greenOrRed] = visited[y][x][!greenOrRed];
				canFlower++;
				continue;
			}

			for (int d = 0; d < 4; ++d) {
				int next_y = y + dy[d];
				int next_x = x + dx[d];

				if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
					continue;
				}

				if (m[next_y][next_x] != '0') {
					if (visited[next_y][next_x][greenOrRed] == -1) {
						visited[next_y][next_x][greenOrRed] = visited[y][x][greenOrRed] + 1;
						q.push({ {next_y, next_x}, greenOrRed });
					}
				}

			}

		}

		ans = max(ans, canFlower);

		return;
	}


	if (i >= canSeed.size()) {
		return;
	}

	if (g > 0) {
		seed.push_back({ canSeed[i], true });
		dfs(i + 1, g - 1, r, seed);
		seed.pop_back();
	}


	if (r > 0) {
		seed.push_back({ canSeed[i], false });
		dfs(i + 1, g, r - 1, seed);
		seed.pop_back();
	}

	dfs(i + 1, g, r, seed);

}

int main(void) {

	cin >> N >> M >> G >> R;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> m[i][j];

			if (m[i][j] == '2') {
				canSeed.push_back({ i, j });
			}
		}
	}

	vector<pair<pair<int, int>, bool>> seed;

	dfs(0, G, R, seed);

	cout << (ans/2) << endl;

}
