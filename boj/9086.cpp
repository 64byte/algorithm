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

	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	int N;
	cin >> N;

	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;

		cout << s[0];
		cout << s[s.size() - 1];
		cout << endl;
	}


}
