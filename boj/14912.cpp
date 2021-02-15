/*
https://www.acmicpc.net/problem/14912

1~n까지

자리수 나누면서 d인 갯수를 세면 된다.

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

	int n, d;
	cin >> n >> d;

	int value = 0;

	int count = 0;
	for (int i = 1; i <= n; ++i) {

		value = i;
		while (value) {


			if ((value%10) == d) {
				count++;
			}

			value /= 10;
		}


	}

	cout << count << endl;
}
