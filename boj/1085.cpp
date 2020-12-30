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

	long long x, y, w, h;

	cin >> x >> y >> w >> h;
	
	long a = min(abs(x - 0), abs(w - x));

	long b = min(abs(y - 0), abs(y - h));

	long c = min(a, b);

	cout << c << endl;
	
}
