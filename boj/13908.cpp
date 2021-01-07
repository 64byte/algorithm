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

bool hasDigit[10];

vector<string> vs;
int ans = 0;

void rec(int idx, int N, string& s) {
	if (s.size() == N) {

		bool hasContain = true;
		for (const auto& v : vs) {
			if (s.find(v) == -1) {
				hasContain = false;
			}

		}

		if (hasContain) {
			ans++;
		}

		return;
	}

	for (int i = 0; i <= 9; ++i) {
		s += (i + '0');
		rec(idx + 1, N, s);

		s.pop_back();
	}

}


int main(void) {

	int N;
	int M;

	cin >> N >> M;


	int value = 0;
	for (int i = 0; i < M; ++i) {
		cin >> value;
		vs.push_back(to_string(value));
	}

	string s = "";
	rec(0, N, s);

	cout << ans << endl;

}
