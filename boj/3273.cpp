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
#include <tuple>

using namespace std;

int main(void) {
	int N;
	vector<int> v;

	cin >> N;
	
	int value;
	for (int i=0; i<N; ++i)
	{
		cin >> value;
		v.push_back(value);
	}

	sort(v.begin(), v.end());

	int x;
	cin >> x;

	int start = 0;
	int end = N - 1;

	int sum = 0;

	int count = 0;
	while (start < end)
	{
		sum = v[start] + v[end];
		if (sum == x)
		{
			start++;
			count++;
		}
		else if (sum < x)
		{
			start++;
		}
		else
		{
			end--;
		}
		
	}

	cout << count << endl;
	
}
