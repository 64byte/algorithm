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

set<string> ans;

char m[7][7];
vector<pair<int, int>> pairs;
vector<pair<int, int>> teachers;
vector<pair<int, int>> students;

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { -1, 1, 0, 0 };

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> m[i][j];
			if (m[i][j] == 'X') {
				pairs.push_back({ i, j });
			}
			else if (m[i][j] == 'T') {
				teachers.push_back({ i, j });
			}
			else if (m[i][j] == 'S') {
				students.push_back({ i, j });
			}
		}
	}

	vector<bool> visited;
	for (int i = 0; i < pairs.size() - 3; ++i) {
		visited.push_back(false);
	}

	for (int i = 0; i < 3; ++i) {
		visited.push_back(true);
	}

	string ans = "NO";

	do {
		bool seen = false;

		for (int i = 0; i < pairs.size(); ++i) {
			if (visited[i]) {
				m[pairs[i].first][pairs[i].second] = 'O';
			}
		}

		for (int i = 0; i < students.size(); ++i) {

			int y = students[i].first;
			int x = students[i].second;

			for (int j = 0; j < 4; ++j) {

				int next_y = y;
				int next_x = x;

				do {
					next_y += dy[j];
					next_x += dx[j];

					if (m[next_y][next_x] == 'O') {
						break;
					}

					if (m[next_y][next_x] == 'T') {
						seen = true;
						break;
					}


				} while (next_y >= 0 && next_y < N && next_x >= 0 && next_x < N);

				if (seen) {
					break;
				}
			}
		}

		if (!seen) {
			ans = "YES";
			break;
		}

		for (int i = 0; i < pairs.size(); ++i) {
			if (visited[i]) {
				m[pairs[i].first][pairs[i].second] = 'X';
			}
		}

	} while (next_permutation(visited.begin(), visited.end()));

	cout << ans << endl;
}
