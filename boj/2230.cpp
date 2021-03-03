/*
https://www.acmicpc.net/problem/2230

투 포인터 문제.

문제에서 같은 수를 고를 수 있다.를 잘못 이해해서 오답을 많이 냈다 ...

이 말은 즉, start와 end가 같아 질 수 있단 말.

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
#include <string>
#include <stack>
#include <tuple>

using namespace std;

int main(void) {
	long long N, M;

	cin >> N >> M;

	long long value;

	vector<long long> g;
	for (int i = 0; i < N; ++i)
	{
		cin >> value;
		g.push_back(value);
	}

	sort(g.begin(), g.end());

	int start = 0;
	int end = 1;

	long long sum = 0;

	long long ans = LLONG_MAX;
	while (start < N && end < N)
	{
		sum = g[end] - g[start];
		if (sum == M) {
			ans = sum;
			break;
		}


		if (sum < M) {
			end++;
		}
		else if (sum > M) {
			ans = min(ans, sum);
			start++;
		}

	}

	cout << ans << endl;
}
