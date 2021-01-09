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
	int N;
	cin >> N;

	int c = 1;
	for (int i = 0; i < 2 * N - 1; ++i) {
		
		for (int j = 0; j < c; ++j) {
			cout << "*";
		}
		cout << "\n";
		if (i >= N-1) {
			c--;
		}
		else if (i < N) {
			c++;
		}

	}

}
