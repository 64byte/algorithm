/*
https://www.acmicpc.net/problem/1766

위상 정렬 문제

그래프 관계를 설정하고 풀었으나 O(N^2)로 풀었음.

우선순위 큐로 풀면 O(N)이 된다.

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

vector<int> g[32001];

int main(void) {

	int N, M;
	cin >> N >> M;

	vector<int> inPQ(N + 1, 0);
	priority_queue<int, vector<int>, greater<>> pq;

	int a1, b1;
	for (int i = 0; i < M; ++i) {
		cin >> a1 >> b1;
		g[a1].push_back(b1);
		inPQ[b1]++;
	}

	for (int i = 1; i <= N; ++i) {
		if (inPQ[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int node = pq.top();

		pq.pop();

		cout << node << " ";
		for (int i = 0; i < g[node].size(); ++i) {
			int idx = g[node][i];


			inPQ[idx]--;
			if (inPQ[idx] == 0) {
				pq.push(idx);
			}

		}


	}
	cout << endl;
}
