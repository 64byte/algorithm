/*

재귀 함수 

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

char m[7][7];

vector<pair<int, int>> S;
//vector<pair<int, int>> T;
vector<pair<int, int>> E;

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { 1, -1, 0, 0 };

bool ans = false;

void dfs(int i, int r, vector<pair<int, int>>& o) {

	if (ans) {
		return;
	}

	if (r == 0) {
		for (const auto& xy : o) {
			m[xy.first][xy.second] = 'O';
		}

		bool seen = false;

		for (const auto& s : S) {
			
			for (int d = 0; d < 4; ++d) {

				int next_y = s.first + dy[d];;
				int next_x = s.second + dx[d];;

				while (true) {

					if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) {
						break;
					}

					if (m[next_y][next_x] == 'O') {
						break;
					}

					if (m[next_y][next_x] == 'S') {
						break;
					}

					if (m[next_y][next_x] == 'T') {
						seen = true;
						break;
					}


					next_y += dy[d];
					next_x += dx[d];

				}

			}
		}

		if (!seen) {
			ans = true;
			return;
		}

		for (const auto& xy : o) {
			m[xy.first][xy.second] = 'X';
		}
		return;
	}

	if (i >= E.size()) {
		return;
	}


	o.push_back(E[i]);
	dfs(i + 1, r - 1, o);
	o.pop_back();

	dfs(i + 1, r, o);

}


int main(void) {


	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> m[i][j];
			if (m[i][j] == 'X') {
				E.push_back({ i, j });
			}
			else if (m[i][j] == 'S') {
				S.push_back({ i, j });
			}
		}
	}

	vector<pair<int, int>> o;

	dfs(0, 3, o);


	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

*/
---

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
