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

	int T;
	cin >> T;

	int n, m;
	int count = 0;
	for (int i = 0; i < T; ++i) {
		cin >> n >> m;
		count = 0;

		for (int a = 1; a < n; ++a) {
			for (int b = a + 1; b < n; ++b) {

				double res1 = (a * a + b * b + m) / static_cast<double>(a * b);
				long res2 = res1;

				if (res1 == res2) {
					count++;
				}

			}
		}

		cout << count << endl;

	}
}
