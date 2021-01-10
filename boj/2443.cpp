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
	int N;
	cin >> N;

	int y = 0;
	int x = 2 * N-1;


	for (int i = 1; i <= N; ++i) {
		
		for (int j = 0; j < y; ++j) {
			cout << " ";
		}

		for (int j = 0; j < x; ++j) {
			cout << "*";
		}

		cout << "\n";

		y++;
		x -= 2;

	}

}
