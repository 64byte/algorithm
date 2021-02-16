/*
https://www.acmicpc.net/problem/11278

11277 문제와 같다.

2-cnf식이 true로 만들 수 있을 경우에, 고른 경우의 수를 저장해서 출력한다.

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


int N, M;

vector<pair<int, int>> cnf;

bool ans = false;
vector<vector<bool>> ansValues;

void rec(int i, vector<bool>& v) {

	if (i == N) {

		bool canMake = true;
		for (int j = 0; j < cnf.size(); ++j) {
			int v1 = abs(cnf[j].first) - 1;
			int v2 = abs(cnf[j].second) - 1;
			bool firstBool = cnf[j].first < 0 ? !v[v1] : v[v1];
			bool secondBool = cnf[j].second < 0 ? !v[v2] : v[v2];

			if (! (firstBool || secondBool)) {
				canMake = false;
				break;
			}

		}

		if (canMake) {
			ans = true;
			ansValues.push_back(v);
		}


		return;
	}

	v.push_back(true);
	rec(i + 1, v);
	v.pop_back();

	v.push_back(false);
	rec(i + 1, v);
	v.pop_back();




}

int main(void) {

	cin >> N >> M;

	int v1 = 0, v2 = 0;
	for (int i = 0; i < M; ++i) {
		cin >> v1 >> v2;
		cnf.push_back({ v1, v2 });
	}

	vector<bool> vv;


	rec(0, vv);

	if (ans) {
		cout << ans << endl;
		//for (const auto& an : ansValues) {
			for (const auto& v : ansValues[0]) {
				cout << v << " ";
			}
			cout << endl;
		//}
	}
	else {
		cout << ans << endl;
	}

}
