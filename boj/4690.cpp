/*
https://www.acmicpc.net/problem/4690



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


int N, M;

vector<pair<int, int>> cnf;

bool ans = false;
vector<vector<bool>> ansValues;

long long powll3(long long a) {
	return a * a * a;
}

int main(void) {

	long long a = 0, b = 0, c = 0, d = 0;

	for (a = 1; a <= 100; ++a) {

		for (b = 2; b <= 100; ++b) {
			for (c = b+1; c <= 100; ++c) {
				for (d = c+1; d <= 100; ++d) {

					if (powll3(a) == (powll3(b) + powll3(c) + powll3(d))) {
						printf("Cube = %lld, Triple = (%lld,%lld,%lld)\n", a, b, c, d);
					}

				}
			}
		}
	}


}
