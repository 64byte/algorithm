/*
https://www.acmicpc.net/problem/19532

이하 생략

*/

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

	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	for (int y = -999; y <= 999; ++y) {
		for (int x = -999; x <= 999; ++x) {

			if (a * x + b * y == c && d * x + e * y == f) {

				cout << x << " " << y << endl;
				return 0;
			}

		}
	}


	return 0;

}
