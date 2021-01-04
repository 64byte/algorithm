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

void rec(long long sum, int N, vector<int>& g, int& count, int K) {

	if (sum > N) {
		return;
	}

	if (sum == N) {
		if (count == K-1) {
			for (const auto& c : g) {
				ans += (c + '0');
				ans += '+';
			}
		}

		count++;
	}
	
	g.push_back(1);
	rec(sum + 1, N, g, count, K);
	g.pop_back();

	g.push_back(2);
	rec(sum + 2, N, g, count, K);
	g.pop_back();

	g.push_back(3);
	rec(sum + 3, N, g, count, K);
	g.pop_back();

}

int main(void) {
	int N, K;

	cin >> N >> K;

	vector<int> g;
	int count = 0;
	rec(0, N, g, count, K);

	if (ans == "") {
		cout << "-1" << endl;
	}
	else {
		cout << ans.substr(0, ans.size() - 1) << endl;
	}

}
