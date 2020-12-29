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

	int N, M;

	cin >> N >> M;

	vector<int> g;

	int value;
	for (int i=0; i<N; ++i)
	{
		cin >> value;
		g.push_back(value);
	}
	
	int start = 0;
	int end = 0;

	int sum = 0;
	int count = 0;
	while (end != N || sum >= M)
	{
		if (sum < M)
		{
			sum += g[end];
			end++;
		}
		else if (sum >= M)
		{
			sum -= g[start];
			start++;
		}

		if (sum == M)
		{
			count++;
		}		
	}

	cout << count << "\n";
	
}
