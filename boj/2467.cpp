/*
2470
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
#include <string>
#include <stack>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;

	vector<long long> g;

	int value;
	for (int i = 0; i < N; ++i)
	{
		cin >> value;
		g.push_back(value);
	}

	int start = 0;
	int end = N - 1;

	int count = 0;

	long long sum = 0;
	long long dist = 9876543210;

	long long ans1 = 0;
	long long ans2 = 0;

	sort(g.begin(), g.end());
	while (start < end)
	{
		sum = g[start] + g[end];

		if (abs(dist) > abs(sum))
		{
			dist = sum;
			ans1 = g[start];
			ans2 = g[end];
		}

		if (sum < 0)
		{
			start++;
		}
		else
		{
			end--;
		}

	}

	cout << ans1 << " " << ans2 << "\n";
}
