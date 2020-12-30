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

	long long A, B, C;

	cin >> A >> B >> C;

	long long w = C - B;
	
	if (w <= 0)
	{
		cout << "-1" << endl;
	}
	else
	{
		long long ans = A / w + 1;
		cout << ans << endl;
	}
	
}
