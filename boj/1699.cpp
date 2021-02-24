/*
https://www.acmicpc.net/problem/1699

제곱수의 합을 구하는 dp 문제



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

long long dp[100001];

int main(void) {

	int N;

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		dp[i] = i;

		for (int j = 1; j * j <= i; ++j) {

			dp[i] = min(dp[i], dp[i - j * j] + 1);

		}

	}

	cout << dp[N] << endl;

}
