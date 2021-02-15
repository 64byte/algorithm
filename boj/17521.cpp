/*
https://www.acmicpc.net/problem/17521

brute force, 경우의 수를 다 만들어보면 된다.

n의 범위가 1~15밖에 안되기 때문에
구매, 판매, 아무것도 하지 않기를 조각 문제로 만들어서 호출

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

long long n;
long long W;
vector<long long> g;

long long ans = LLONG_MIN;

void calc(long long i, long long w, long long curr) {

	if (i >= g.size()) {
		long long lastDaySell = 0;
		if (curr > 0) {
			lastDaySell = (g.back() * curr);
		}

		ans = max(ans, w + lastDaySell);
		return;
	}

	long long count = w / g[i];
	if (count > 0) {
		calc(i + 1, w - g[i] * count, curr + count);
	}

	if (curr > 0) {
		calc(i + 1, w + g[i] * curr, 0);
	}

	calc(i + 1, w, curr);

}

int main(void) {

	cin >> n >> W;

	long long value;
	for (int i = 0; i < n; ++i) {
		cin >> value;
		g.push_back(value);
	}

	calc(0, W, 0);

	cout << ans << endl;
}
