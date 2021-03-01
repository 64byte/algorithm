/*
https://www.acmicpc.net/problem/11052

dp는 너무 어렵다....



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

using ll = long long;

const ll INF = 987654321;

int cards[1001];
int dp[1001];


int main(void) {
	int N;
	cin >> N;

	int value = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> cards[i];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] = max(dp[i], dp[i - j] + cards[j]);
		}
	}

	cout << dp[N] << endl;
}
