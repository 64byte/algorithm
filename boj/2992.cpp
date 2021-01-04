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

long long A, B;
long long ans = 0;

vector<vector<int>> gg;

bool visited[10];

long c = 9876543210;

void rec(int idx, int N, string& s, long long curr) {

	if (idx >= N) {
		return;
	}

	if (curr < stol(s)) {
		c = min(c, stol(s));
	}


	for (int i = 0; i < N; ++i) {
		if (visited[i]) {
			continue;
		}

		visited[i] = true;

		swap(s[idx], s[i]);

		rec(idx + 1, N, s, curr);

		visited[i] = false;

		swap(s[idx], s[i]);
	}

}

int main(void) {
	string s;
	cin >> s;

	rec(0, s.size(), s, stol(s));

    if (c == 9876543210) {
        cout << "0" << endl;
    } else {
	    cout << c << endl;
    }

}
