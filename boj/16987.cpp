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
bool visited[10][10];
int ans = 0;

void dfs(int idx, vector<pair<int, int>>& eggs, int count) {

	if (idx >= N) {
		ans = max(ans, count);
		return;
	}


	if (eggs[idx].first <= 0) {
		dfs(idx + 1, eggs, count);
	}
	else {

		bool attackedEgg = false;
		for (int i = 0; i < eggs.size(); ++i)
		{
			if (idx != i && eggs[idx].first > 0 && eggs[i].first > 0) {
				attackedEgg = true;

				eggs[idx].first -= eggs[i].second;
				eggs[i].first -= eggs[idx].second;

				if (eggs[idx].first <= 0) {
					count += 1;
				}

				if (eggs[i].first <= 0) {
					count++;
				}

				dfs(idx + 1, eggs, count);

				if (eggs[idx].first <= 0) {
					count -= 1;
				}

				if (eggs[i].first <= 0) {
					count--;
				}

				eggs[idx].first += eggs[i].second;
				eggs[i].first += eggs[idx].second;
			}

		}

		if (!attackedEgg) {
			ans = max(ans, count);
			return;
		}

	}
}

int main(void) {

	vector<pair<int, int>> eggs;

	cin >> N;

	int v, w;

	for (int i = 0; i < N; ++i) {
		cin >> v >> w;
		eggs.push_back({ v, w });
	}

	dfs(0, eggs, 0);

	cout << ans << endl;
}
