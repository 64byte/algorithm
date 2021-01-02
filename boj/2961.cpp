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

long long ans = 98765432100;

void dfs(int idx, vector<pair<int, int>>& g, int diff, vector<pair<int, int>>& tmp) {

	if (tmp.size() >= 1) {
		long long ss = 1;
		long long bb = 0;
		for (const auto& t : tmp) {
			ss *= t.first;
			bb += t.second;
		}

		ans = min(ans, abs(ss - bb));
	}

	if (idx >= g.size()) {
		return;
	}

	tmp.push_back(g[idx]);
	dfs(idx + 1, g, diff, tmp);
	tmp.pop_back();

	dfs(idx + 1, g, diff, tmp);

}

int main(void) {
	int N;
	cin >> N;

	int s, b;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i) {
		cin >> s >> b;
		v.push_back({ s, b });
	}

	vector<pair<int, int>> tmp;

	dfs(0, v, 0, tmp);

	cout << ans << endl;
}
