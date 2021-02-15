/*
https://www.acmicpc.net/problem/14650

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


int N;

int answer = 0;

vector<long long> values{ 0, 1, 2 };


void dfs(int i, long long nCount, long long curr) {

	if (i >= N) {
		long long n = curr;
		long long count = 0;
		while (n) {
			n /= 10;
			count++;
		}


		if (N == count && curr > 0 && curr % 3 == 0) {
			answer++;
		}

		return;
	}


	for (int k = 0; k < values.size(); ++k) {

		dfs(i + 1, nCount * 10, curr + (values[k] * nCount));

	}

}


int main(void) {

	cin >> N;

	vector<int> ans;

	dfs(0, 1, 0);

	cout << answer << endl;

}
