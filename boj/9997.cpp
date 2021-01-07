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

bool visited[26];

int ans = 0;
long allContains = 0;
vector<long> vs;

void rec(int idx, vector<long>& vs, long curr) {

	if (idx == vs.size()) {
		if (curr == allContains) {
			ans++;
		}
		return;
	}

	rec(idx + 1, vs, curr | vs[idx]);

	rec(idx + 1, vs, curr);

}

int main(void) {

	int N;
	string s;

	cin >> N;

	long long digits = 0;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		digits = 0;
		
		for (int j = 0; j < s.size(); ++j) {
			digits |= (1 << (s[j] - 'a'));
		}

		vs.push_back(digits);
	}

	for (int i = 0; i < 26; ++i) {
		allContains |= (1 << i);
	}

	rec(0, vs, 0);

	cout << ans << endl;
}
