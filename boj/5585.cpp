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

vector<int> cashes = { 500, 100, 50, 10, 5, 1 };

int main(void) {

	int count = 0;
	int N;

	cin >> N;
	N = 1000 - N;

	int n = 0;
	for (const auto& c : cashes) {
		if (N >= c) {

			n = N / c;
			N -= (n * c);
			count += n;
		}
	}

	cout << count << "\n";
}
