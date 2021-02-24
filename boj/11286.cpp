/*
https://www.acmicpc.net/problem/11286

우선순위큐 기초 문제

pq에 (절대값, 기존값)을 활용한다

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

	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	int N;

	cin >> N;

	priority_queue<pair<long, long>, vector<pair<long, long>>, greater<>> pq;

	long long value = 0;

	for (int i = 0; i < N; ++i) {
		cin >> value;

		if (value == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << "\n";
				pq.pop();
			}
			else {
				cout << "0" << "\n";
			}
		}
		else {
			pq.push({ abs(value), value });
		}

	}
}
