/*
https://www.acmicpc.net/problem/2752



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

	int N = 3;

	priority_queue<int, vector<int>, greater<>> pq;

	int value;
	for (int i = 0; i < N; ++i) {
		cin >> value;
		pq.push(value);
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << "\n";

}
