/*
https://www.acmicpc.net/problem/1715

작은 수를 만들어 더하는 게 최소이니, 

우선 순위 큐에 다 넣고

상위 2개만 뺀 뒤에 더하고 (더한 것은 계속 집계해야함) 나서 큐에 요소가 1개 남을 때까지 반복한다.

시간복잡도는 O(N)

*/
include <iostream>
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

	priority_queue<int, vector<int>, greater<>> pq;

	int ans = 0;

	int value = 0;
	for (int i = 0; i < N; ++i) {
		cin >> value;
		pq.push(value);
	}

	while (pq.size () >= 2) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		pq.push(a + b);

		ans += (a + b);
	}

	cout << ans << endl;

}
