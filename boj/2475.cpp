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

	long long value = 0;

	long long ans = 0;
	for (int i = 0; i < 5; ++i) {
		cin >> value;
		ans += (value * value);
	}

	cout << (ans % 10) << "\n";
}
