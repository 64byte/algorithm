/*
https://www.acmicpc.net/problem/15593

(x, y) 좌표 N개가 주어질 때, 좌표 한 개를 제외했을 때 커버하는 좌표의 범위를 더한 뒤 최대값을 계산.

먼저 정렬을 한 뒤에 순서대로 좌표를 계산하면서 넣음, 마지막에 넣은 좌표y가가 다음 좌표 x를 커버한다면 마지막에 넣은 좌표 y의 범위를 다음 좌표 y로 바꾸고 그게 아니면 스택에 넣음

그 뒤 총 합을 계산

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

	int N;
	cin >> N;

	vector<pair<int, int>> v;

	int a = 0, b = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	int inter = 0;

	stack<pair<int, int>> area;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			if (i != j) {

				if (area.empty()) {
					area.push({ v[j].first, v[j].second });
				}
				else {

					if (area.top().second >= v[j].first) {

						area.top().second = v[j].second;

					}
					else {
						area.push({ v[j].first, v[j].second });
					}
				}
			}

		}

		int result = 0;
		while (!area.empty()) {
			auto node = area.top();
			area.pop();

			result += (node.second - node.first);
		}

		inter = max(inter, result);

	}

	cout << inter << endl;
	return 0;

}
