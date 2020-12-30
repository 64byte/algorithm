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

	long long a, b, c;

	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}

		if (a > b)
			swap(a, b);

		if (b > c)
			swap(b, c);
		
		if ((a * a) + (b * b) == (c * c))
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}
	
}
