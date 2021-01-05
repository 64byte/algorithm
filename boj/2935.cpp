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

	string a;
	char c;
	string b;

	cin >> a;
	cin >> c;
	cin >> b;

	int aSize = a.size();
	int bSize = b.size();

	string ans = "";
	if (c == '*') {
		if (aSize >= bSize) {
			ans = a;
			for (int i = 0; i < bSize - 1; ++i) {
				ans += "0";
			}
		}
		else {
			ans = b;
			for (int i = 0; i < aSize - 1; ++i) {
				ans += "0";
			}
		}


	}
	else if (c == '+') {
		if (aSize > bSize) {
			ans = a;
			ans[aSize - bSize] = '1';

		}
		else if (aSize < bSize) {
			ans = b;

			ans[bSize-aSize] = '1';
		}
		else {
			ans = a;
			ans[0] += 1;
		}

	}

	cout << ans << "\n";

}
