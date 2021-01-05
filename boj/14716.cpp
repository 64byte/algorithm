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

int N, M;

bool visited[251][251];

const int dy[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
const int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

char m[251][251];

void dfs(int y, int x) {

	visited[y][x] = true;

	for (int i = 0; i < 8; ++i) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= M) {
			continue;
		}

		if (!visited[next_y][next_x] && m[next_y][next_x] == '1') {
			dfs(next_y, next_x);
		}
	}

}

int main(void) {

	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> m[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!visited[i][j] && m[i][j] == '1') {
				dfs(i, j);

				count++;
			}
		}
	}

	cout << count << endl;
}
