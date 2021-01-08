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


long long dp[1000001];
const long long DIV = 1000000009;

int main(void) {

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000000; ++i) {

		dp[i] = (dp[i - 1] % DIV) + (dp[i - 2] % DIV) + (dp[i - 3] % DIV);
		dp[i] %= DIV;
	}

	int t;
	cin >> t;

	int n;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << dp[n] << endl;
	}
}
