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

	string s;
	while (true) {
		cin >> s;
		if (s == "0") {
			return 0;
		}

		int sSize = s.size();
		bool isPal = true;
		for (int i = 0, j = sSize - 1; i < sSize && j >= 0; i++, j--) {
			if (s[i] != s[j]) {
				isPal = false;
				break;
			}
		}

		if (isPal) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}

}
