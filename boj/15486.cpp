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

int dp[1500001];

int rec(int idx, vector<pair<int, int>>& v) {

	if (idx >= v.size()) {
		return 0;
	}

	int& ret = dp[idx];
	if (ret != -1) {
		return ret;
	}

	if (v[idx].first + idx <= v.size()) {
		ret = max(ret, rec(idx + v[idx].first, v) + v[idx].second);

	}

	ret = max(ret, rec(idx + 1, v));

	return ret;
}

int main(void) {

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	int t, p;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; ++i) {
		cin >> t >> p;

		v.push_back({ t, p });
	}

	cout << rec(0, v) << endl;
}
