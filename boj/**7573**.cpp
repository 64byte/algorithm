/*
https://www.acmicpc.net/problem/7573

복습 필요한 문제.

N <= 10000까지이니 단순 완전탐색으론 풀기 힘들다. N^2 * (I/2)^2 * M = 시간 초과

물고기 기준으로 문제를 푼다. M <= 100

---

물고기 기준으로 문제를 푸는 것은 잘 생각했으나 그물을 놓는 방법을 잘못 생각했다.

물고기 기준으로 (mX1 - iX1, mY1 - iY1) ~ (mX2 + iX2, mY2 + iY2)의 그믈울 치고 물고기를 확인한다.



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

vector<pair<int, int>> fishes;
vector<pair<int, int>> nets;

int main(void) {

	int N, I, M;

	cin >> N >> I >> M;
	
	int a = 0, b = 0;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		fishes.push_back({ a, b });
	}

	int w = I / 2-1;

	int y = 1, x = w;
	for (int j = 0; j < w; ++j) {
		nets.push_back({ y, x });

		y++;
		x--;
	}

	int ans = 0;
	int count = 0;

	for (const auto& ne : nets) {

		for (int fi = 0; fi < fishes.size(); ++ fi) {
		
			for (int y = fishes[fi].first - ne.first; y < fishes[fi].first + ne.first; ++y) {

				for (int x = fishes[fi].second - ne.second; x < fishes[fi].second + ne.second; ++x) {

					count = 0;

					for (int nfi = fi; nfi < fishes.size(); ++nfi) {
						if (fishes[nfi].first < y || y + ne.first < fishes[nfi].first || fishes[nfi].second < x || x + ne.second < fishes[nfi].second)
							continue;

						count++;
					}

					ans = max(ans, count);
				}
			}


		}


	}


	cout << ans << endl;

	return 0;

}
