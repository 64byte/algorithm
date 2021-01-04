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

string ans = "";

bool isPalandrome(string s) {

	int sSize = s.size();

	for (int i = 0, j = sSize - 1; i < sSize && j >= 0; ++i, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	int T;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		vector<bool> visited;
		vector<string> ss(N);

		for (int j = 0; j < N; ++j) {
			cin >> ss[j];
		}

		int k = 2;
		for (int j = 0; j < N - k; ++j) {
			visited.push_back(0);
		}

		for (int j = 0; j < k; ++j) {
			visited.push_back(1);
		}

		string ans = "";
		string pal = "";

		vector<string> g;
		do {

			g.clear();
			for (int j = 0; j < N; ++j) {
				if (visited[j]) {
					g.push_back(ss[j]);
				}
			}

			if (g.size() == k) {
				pal = g[0] + g[1];
				if (isPalandrome(g[0] + g[1])) {
					ans = pal;
				}

				pal = g[1] + g[0];
				if (isPalandrome(g[1] + g[0])) {
					ans = pal;
				}
			}


		} while (next_permutation(visited.begin(), visited.end()));

		if (ans == "") {
			cout << "0" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
}
