/*
https://www.acmicpc.net/problem/10886

읽으면 풀 수 있는 문제

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



int main(void) {

	int N = 0;
	cin >> N;


	int dp[2] = { 0 };

	int v = 0;
	for (int i = 0; i < N; ++i) {
		cin >> v;
		dp[v]++;
	}

	cout << "Junhee is ";
	if (dp[0] > dp[1]) {
		cout << "not cute!" << endl;
	}
	else {
		cout << "cute!" << endl;
	}


}
