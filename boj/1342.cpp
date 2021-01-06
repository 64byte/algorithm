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
	string s;

	cin >> s;
	sort(s.begin(), s.end());

	int ans = 0;

	if (s == "") {
		cout << "0" << endl;
	}
	else {
		do {
			bool luckyStr = true;
			char curr = 0;
			for (int i = 0; i < s.size(); ++i) {
				if (curr == s[i]) {
					luckyStr = false;
				}

				curr = s[i];
			}

			if (luckyStr) {
				ans++;
			}

		} while (next_permutation(s.begin(), s.end()));


		cout << ans << endl;
	}
}
