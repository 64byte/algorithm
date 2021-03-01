/*
https://www.acmicpc.net/problem/1300



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

int main(void) {

	int n, k;
	cin >> n >> k;

	int start = 1;
	int end = k;

	int count = 0;
	int ans = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		count = 0;

		for (int i = 1; i <= n; ++i) {
			count += min(mid / i, n);
		}

		if (count < k) {
			start = mid + 1;
		}
		else  {
			ans = mid;
			end = mid - 1;
		}


	}
	
	cout << ans << endl;
}
