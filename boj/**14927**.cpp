/*
https://www.acmicpc.net/problem/14927

생각해보기.

전구는 2번 이상 누를 필요가 없다. (0, 1 상태. r,g,b라면 2번만 누르면 된다. r->g, g->b, b->r)

순서 강제하기.

순서는 왼쪽에서 오른쪽으로 누른다.

y, x가 있을 때, y-1, x가 켜져있으면 y, x를 누른다. 그래야 y-1, x가 바뀌니까.

첫 번째 열은 위가 없으니 다 눌러 봐야한다.

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

int N;
vector<vector<bool>> m;
set<vector<vector<bool>>> visited;

vector<vector<bool>> empties;

const int dy[5] = { -1, 1, 0, 0, 0 };
const int dx[5] = { 0, 0, -1, 1, 0 };

void printMap(vector<vector<bool>> m) {

	cout << "map" << endl;

	for (int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m.size(); ++j) {
			cout << m[i][j];
		}
		cout << "\n";
	}
	cout << "\n";

}

int ans = 987654321;

void p(int r, int c, vector<vector<bool>>& m) {

	if (c == N) {
		vector<vector<bool>> mm = m;
		int cc = 0;

		for (int i = 1; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (mm[i-1][j]) {

					for (int k = 0; k < 5; ++k) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
							continue;
						}

						mm[ny][nx] = !mm[ny][nx];
					}

					r++;

				}
			}
		}

		if (mm == empties) {
			ans = min(ans, r);
		}

		return;
	}

	p(r, c + 1, m);

	vector<vector<bool>> mmm = m;

	for (int k = 0; k < 5; ++k) {
		int ny = dy[k];
		int nx = c + dx[k];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
			continue;
		}

		mmm[ny][nx] = !mmm[ny][nx];
	}

	p(r + 1, c + 1, mmm);

}


int main(void) {

	cin >> N;

	m = vector<vector<bool>>(N, vector<bool>(N));
	empties = vector<vector<bool>>(N, vector<bool>(N));

	bool val = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> val;
			m[i][j] = val;
		}
	}


	p(0, 0, m);

	if (ans == 987654321) {
		cout << "-1" << endl;
	}
	else {
		cout << ans << endl;
	}
}
