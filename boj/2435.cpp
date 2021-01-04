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

int main(void) {
	int N, K;
	cin >> N >> K;

	int value = 0;
	vector<int> g;
	vector<int> dp(N + 1);

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> value;
		g.push_back(value);

		sum += value;
		dp[i+1] = sum;
	}


	int ans = -987654321;

	//int seq = K;
	for (int i = 0; i <= N-K; i++) {
		ans = max(ans, dp[i+K] - dp[i]);
	}

	cout << ans << endl;
}
