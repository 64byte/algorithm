/*
https://www.acmicpc.net/problem/11277

brute force

N가지 만들 수 있는 경우의 수를 만든다.

N = 3, 000 ~ 111

다 골랐다면, 조건에 맞게 2-cnf식에 대입한다.

경우의 수는 2^N
절의 개수 M

시간 복잡도는 O(2^N*M)

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

	cout << ans << endl;
}
