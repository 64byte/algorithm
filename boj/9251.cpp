/*
https://www.acmicpc.net/problem/9251

완전 탐색 + DP

최장 공통 부분 순열을 찾는 문제.

알고리즘 관련
https://ko.wikipedia.org/wiki/%EC%B5%9C%EC%9E%A5_%EA%B3%B5%ED%86%B5_%EB%B6%80%EB%B6%84_%EC%88%98%EC%97%B4

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


#define INF 987654321

using namespace std;

int dp[1002][1002] = { 0 };

int main(void)
{
	string s1, s2;

	cin >> s1 >> s2;

	

	int count = 0;
	for (int i = 0; i <= s1.size(); ++i) {
		for (int j = 0; j <= s2.size(); ++j) {
			if (s1[i] == s2[j]) {
				dp[i+1][j+1] = dp[i][j] + 1;
			}
			else {
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}

	cout << dp[s1.size()][s2.size()] << endl;
}
