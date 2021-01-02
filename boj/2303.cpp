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
int ans = 0;
int ansValue = 0;

void dfs(int number, int idx, int r, vector<int>& values, int sum) {

	if (r == 0) {
		int oneDigit = sum % 10;
		if (ansValue <= oneDigit) {
			ansValue = oneDigit;
			ans = number;
		}
	}

	if (idx >= values.size()) {
		return;
	}

	dfs(number, idx+1, r - 1, values, sum + values[idx]);
	dfs(number, idx + 1, r, values, sum);
}

int main(void) {

	cin >> N;


	vector<int> v;
	int value = 0;
	for (int j = 0; j < N; ++j) {
		v.clear();
		for (int i = 0; i < 5; ++i) {
			cin >> value;
			v.push_back(value);
		}

		dfs(j+1, 0, 3, v, 0);
	}

	cout << ans << endl;
}
