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

int N;

int main(void) {

	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	cin >> N;
	cin.ignore();
	
	string s;
	for (int i = 0; i < N; ++i) {
		getline(cin, s);

		cout << static_cast<char>(toupper(s[0]));
		for (int i = 1; i < s.size(); ++i) {
			cout << static_cast<char>(s[i]);
		}
		cout << endl;

	}
}
