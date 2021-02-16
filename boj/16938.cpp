/*
https://www.acmicpc.net/problem/16938

문제를 고르는 방법을 다 만들어낸 뒤에

조건에 따라 맞는 방법은 증가하면 된다.

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


long long N, L, R, X;
vector<long long> prob;

int ans = 0;

void rec(int i, vector<long long>& pick) {

	if (i >= prob.size()) {

		if (pick.size() >= 2) {

			long long sum = 0;
			long long minValue = LLONG_MAX;
			long long maxValue = LLONG_MIN;
			for (const auto& p : pick) {

				sum += p;
				maxValue = max(maxValue, p);
				minValue = min(minValue, p);

			}

			if (sum >= L && sum <= R && (maxValue - minValue) >= X) {
				ans++;
			}

		}
		return;
	}

	pick.push_back(prob[i]);
	rec(i + 1, pick);
	pick.pop_back();

	rec(i + 1, pick);

}

int main(void) {

	cin >> N >> L >> R >> X;

	long long value = 0;
	for (int i = 0; i < N; ++i) {
		cin >> value;
		prob.push_back(value);
	}

	vector<long long> pick;

	rec(0, pick);

	cout << ans << endl;
}
