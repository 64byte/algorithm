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

	int N, M;

	cin >> N >> M;

	vector<int> v(N + 1);

	int sum = 0;
	int value = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> value;
		sum += value;
		v[i] = sum;
	}

	int start = 0;
	int end = 0;
	for (int i = 0; i < M; ++i) {
		cin >> start >> end;
		cout << v[end] - v[start-1] << "\n";
	}

}
