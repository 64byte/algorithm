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
	cin >> N;

	int start = 1;
	int end = 1;

	int M = N + 1;

	int sum = 0;

	int count = 0;
	while (end != M || sum >= M)
	{
		if (sum < N)
		{
			sum += end;
			end++;
		}
		else if (sum >= N)
		{
			sum -= start;
			start++;
		}

		if (sum == N)
		{
			count++;
		}		
	}

	cout << count << endl;
	
}
