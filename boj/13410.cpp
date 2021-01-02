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
int main(void) {

	cin >> N >> M;

	string s = "";

	long long ans = 0;
	for (int i = 1; i <= M; ++i) {

		 s = to_string(N * i);
		 reverse(s.begin(), s.end());

		 ans = max(ans, stoll(s));
	}

	cout << ans << endl;
}
